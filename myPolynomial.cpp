#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class myPolynomial;
class myTerm
{
public:
	myTerm(int c = 0, unsigned e = 0);
	// copy constructor
	myTerm(const myTerm& term);
	// overloaded operators
	bool operator == (const myTerm& term) const;
	bool operator != (const myTerm& term) const;
	bool operator < (const myTerm& term) const;
	bool operator > (const myTerm& term) const;
	myTerm operator - () const;
	// accessor functions
	int getCoeff() const { return coeff; }
	unsigned getExp() const { return exp; }
	// mutator functions
	void setCoeff(int c) { coeff = c; }
	void setExp(unsigned e) { exp = e; }
	// member functions
	myTerm ddx() const; // derivative of a term
	// friend functions and classes
	friend ostream& operator <<(ostream& outStream, const myTerm& term);
	friend myPolynomial;
private:
	int coeff; // integer coefficient
	unsigned exp; // exponent (non-negative integer)
};

// Constructor
myTerm::myTerm(int c, unsigned e) : coeff(c), exp(e)
{
}
// copy constructor
myTerm::myTerm(const myTerm& term) : coeff(term.coeff), exp(term.exp)
{
}
// overloaded operators
bool myTerm::operator == (const myTerm& term) const
{
	return coeff == term.coeff && exp == term.exp;
}
// overloaded operators
bool myTerm::operator != (const myTerm& term) const
{
	return !(*this == term);
}
// overloaded operators
bool myTerm::operator < (const myTerm& term) const
{
	return exp < term.exp;
}
bool myTerm::operator > (const myTerm& term) const
{
	return exp > term.exp;
}
myTerm myTerm::operator - () const
{
	myTerm temp = *this;
	temp.coeff = -temp.coeff;
	return temp;
}
// derivative of a term
myTerm myTerm::ddx() const
{
	if (exp == 0)
		return myTerm(0, 0);
	return myTerm(exp * coeff, exp - 1);
}
// output operator
ostream& operator <<(ostream& outStream, const myTerm& term)
{
	if (term.exp == 0)
		if (term.coeff == 0) // nothing to output
			return outStream;
		else
			return outStream << term.coeff;

	if (term.coeff == 1)
		outStream << "x";
	else if (term.coeff == -1)
		outStream << "-x";
	else
		outStream << term.coeff << "x";
	if (term.exp == 1)
		return outStream;
	else
		return outStream << "^" << term.exp;
}
class myPolynomial
{
public:
	myPolynomial(int c = 0, unsigned e = 0);
	myPolynomial(int nTerms, int mono[]);
	//sortTerms
	void sortTerms();
	void addTerms(myTerm &newTerm);
	// copy constructor
	myPolynomial(const myPolynomial& poly);
	// overloaded operators
	bool operator == (const myPolynomial& poly) const;
	bool operator != (const myPolynomial& poly) const;
	myPolynomial& operator += (const myPolynomial& poly);
	myPolynomial& operator -= (const myPolynomial& poly);
	myPolynomial& operator *= (const myPolynomial& poly);
	myPolynomial& operator *= (int k);
	myPolynomial operator -() const;
	myPolynomial operator *(int k) const;
	myPolynomial operator +(const myPolynomial& poly) const;
	myPolynomial operator -(const myPolynomial& poly) const;
	myPolynomial operator *(const myPolynomial& poly) const;

	long operator() (int x) const; // evaluate the polynomial
	int getDegree() const; // get a degree of the polynomial
	unsigned getNumTerms() const; // number of terms in the polynomial
	myPolynomial ddx() const; // derivative of a polynomial
	// friend operators and functions
	friend myPolynomial operator *(int k, const myPolynomial& poly);
	friend ostream& operator <<(ostream& outStream, const myPolynomial& poly);
	static const myPolynomial ZERO; // P(x) = 0
	static const myPolynomial ONE; // P(x) = 1
	static const myPolynomial X; // P(x) = x
private:
	int degree; // maximum expnent
	std::list<myTerm> terms{};
};

// constructor
myPolynomial::myPolynomial(int c, unsigned e)
{
	degree = e;
	terms.push_back(myTerm(c, e));
}
myPolynomial::myPolynomial(int nTerms, int mono[])
{
	vector<myTerm> tempTerms;
	for (int i = 0; i < nTerms; ++i) {
		tempTerms.push_back(myTerm(mono[2 * i], mono[2 * i + 1]));
	}
	sort(tempTerms.begin(), tempTerms.end(),
		[](const myTerm& a, const myTerm& b) { return a.getExp() > b.getExp(); });
	for (const myTerm& term : tempTerms) {
		terms.push_back(term);
	}
	degree = terms.front().getExp();
}

// sort
void myPolynomial::sortTerms() {
	terms.sort([](const myTerm& a, const myTerm& b) {
		return a.getExp() > b.getExp();
		});
	terms.remove_if([](const myTerm& term) {
		return term.getCoeff() == 0;
		});
}
void myPolynomial::addTerms(myTerm& newTerm)
{
	for (auto& term : terms) {
		if (term.getExp() == newTerm.getExp()) {
			term.setCoeff(term.getCoeff() + newTerm.getCoeff());
			return;
		}
	}

	// If there is no existing term with the same exponent, add the new term
	terms.push_back(newTerm);
}
// copy constructor
myPolynomial::myPolynomial(const myPolynomial& poly)
{
	degree = poly.degree;
	terms = poly.terms;
}
// overloaded operators
bool myPolynomial::operator == (const myPolynomial& poly) const
{
	return degree == poly.degree && terms == poly.terms;
}
bool myPolynomial::operator != (const myPolynomial& poly) const
{
	return !(*this == poly);
}

myPolynomial& myPolynomial::operator+= (const myPolynomial& poly)
{
	myPolynomial newPoly = *this + poly;
	
	*this = newPoly;
	return *this;
}
myPolynomial& myPolynomial::operator-= (const myPolynomial& poly)
{
	myPolynomial newPoly = *this - poly;

	*this = newPoly;
	return *this;
}
myPolynomial& myPolynomial::operator*= (const myPolynomial& poly)
{
	myPolynomial newPoly = *this * poly;

	*this = newPoly;
	return *this;
}
myPolynomial& myPolynomial::operator*=(const int k)
{
	myPolynomial newPoly = *this * k;
	*this = newPoly;
	return *this;
}

myPolynomial myPolynomial::operator-() const
{
	myPolynomial poly(*this);
	for (myTerm& term : poly.terms)
	{
		term.coeff = -term.coeff;
	}
	
	return poly;
}

myPolynomial myPolynomial::operator*(int value) const {
	myPolynomial result;
	for (const auto& term : terms) {
		myTerm newTerm = term;
		newTerm.coeff = value * newTerm.getCoeff();
		result.addTerms(newTerm);
	}

	result.sortTerms();
	return result;
}
myPolynomial myPolynomial::operator*(const myPolynomial& rhs) const {

	myPolynomial result;
	for (const auto& lhsTerm : this->terms) {
		for (const auto& rhsTerm : rhs.terms) {
			int newCoeff = lhsTerm.getCoeff() * rhsTerm.getCoeff();
			int newExp = lhsTerm.getExp() + rhsTerm.getExp();

			myTerm newTerm(newCoeff, newExp);
			result.addTerms(newTerm);
		}
	}

	result.sortTerms(); // This will sort and combine like terms
	return result;
}

myPolynomial myPolynomial::operator+(const myPolynomial& poly) const
{
	myPolynomial sum(*this); // 덧셈 결과를 저장할 객체를 생성하고 현재 객체(*this)를 복사합니다.

	for (const myTerm& term : poly.terms) {
		bool termExists = false;

		for (myTerm& existingTerm : sum.terms) {
			if (existingTerm.getExp() == term.getExp()) {
				existingTerm.setCoeff(existingTerm.getCoeff() + term.getCoeff());
				termExists = true;
				break;
			}
		}

		if (!termExists) { // 만약 같은 차수의 항이 없으면, 새 항을 추가합니다.
			sum.terms.push_back(term);
		}
	}

	sum.sortTerms(); // 결과를 차수가 높은 순으로 정렬합니다.

	return sum;
}
myPolynomial myPolynomial::operator-(const myPolynomial& poly) const
{
	myPolynomial sum(*this); // 덧셈 결과를 저장할 객체를 생성하고 현재 객체(*this)를 복사합니다.

	for (const myTerm& term : poly.terms) {
		bool termExists = false;

		for (myTerm& existingTerm : sum.terms) {
			if (existingTerm.getExp() == term.getExp()) {
				existingTerm.setCoeff(existingTerm.getCoeff() - term.getCoeff());
				termExists = true;
				break;
			}
		}

		if (!termExists) { // 만약 같은 차수의 항이 없으면, 새 항을 추가합니다.
			myTerm newTerm(-term.getCoeff(), term.getExp());
			sum.terms.push_back(newTerm);
		}
	}

	sum.sortTerms(); // 결과를 차수가 높은 순으로 정렬합니다.

	return sum;
}

long myPolynomial::operator() (int x) const {
	long result = 0;
	for (const myTerm& term : terms) {
		result += term.getCoeff() * pow(x, term.getExp());
	}
	return result;
}
int myPolynomial::getDegree() const
{
	return degree;
}

unsigned myPolynomial::getNumTerms() const
{
	return terms.size();
}
myPolynomial myPolynomial::ddx() const
{
	myPolynomial result;
	
	for (myTerm term : terms)
	{
		myTerm newTerm = term.ddx();
		result.addTerms(newTerm);
	}

	result.sortTerms();
	
	return result;
}

myPolynomial operator*(int k, const myPolynomial& poly)
{
	return poly * k;
}

ostream& operator<<(ostream& outStream, const myPolynomial& poly)
{
	if (poly.terms.empty() || poly == myPolynomial::ZERO){
		outStream << 0;
		return outStream;
	}

	bool first = true;
	for (const myTerm& term : poly.terms) {
		if (first)
		{
			first = false;
			outStream << term;
		}
		else
		{
			if (term.getCoeff() > 0) {
				outStream << "+" << term;
			}
			else if (term.getCoeff() < 0) {
				outStream << "-" << -term;
			}
			else {
				continue;
			}
		}
	}

	return outStream;
}
const myPolynomial myPolynomial::ZERO(0); // the zero polynomial P(x) = 0
const myPolynomial myPolynomial::ONE(1, (unsigned)0); // the monomial P(x) = 1
const myPolynomial myPolynomial::X(1, 1); // the monomial P(x) = x

void testSimpleCase();
void testDataFromFile();
int main(void)
{
	testSimpleCase();
	testDataFromFile();
	return 0;
}
void testSimpleCase()
{
	// test static variables
	cout << myPolynomial::ZERO << endl;
	cout << myPolynomial::ONE << endl;
	cout << myPolynomial::X << endl;
	myPolynomial p0, p1(1), p2(1, 1), p3(3, 5);
	int testData4[10] = { 1, 0, 1, 1, 1, 2, 1, 3, 1, 4 };
	int testData5[10] = { -1, 0, -1, 1, -1, 2, -1, 3, -1, 4 };
	int testData6[10] = { 1, 0, -1, 1, 1, 2, -1, 3, 1, 4 };
	int testData7[10] = { 2, 2, 5, 5, 4, 4, 1, 1, 3, 3 };
	int testData8[12] = { 1, 1000000000, 1, 100000000, 1, 1000000, 1, 10000, 1,
	100, 1, 0 };
	myPolynomial p4(5, testData4);
	myPolynomial p5(5, testData5);
	myPolynomial p6(5, testData6);
	myPolynomial p7(5, testData7);
	myPolynomial p8(6, testData8);
	myPolynomial p9(p7);
	// test constructor
	cout << p0 << endl << p1 << endl << p2 << endl;
	cout << p4 << endl << p8 << endl;
	// test copy constructor
	cout << p9 << endl;
	// test accessor function
	cout << p8.getDegree() << " " << p8.getNumTerms() << endl;
	// test evaluation function
	cout << p1(2) << " " << p2(2) << " " << p3(2) << " " << p4(2) << " " << endl;
	cout << p5(3) << " " << p6(3) << " " << p7(3) << " " << p9(3) << " " << endl;
	// test comparison operators
	cout << (p7 == p9) << " " << (p7 != p9) << endl;
	// test derivative function
	cout << myPolynomial::ZERO.ddx() << endl;
	cout << myPolynomial::ONE.ddx() << endl;
	cout << myPolynomial::X.ddx() << endl;
	cout << p4.ddx() << endl;
	cout << p8.ddx() << endl;
	// test unary operator -
	cout << -myPolynomial::ZERO << endl;
	cout << -p4 << endl;
	// test k*p(x) or p(x) * k
	cout << 3 * myPolynomial::ZERO << endl;
	cout << 3 * myPolynomial::ONE << endl; //
	cout << myPolynomial::X * 3 << endl; //
	cout << 3 * p4 << " " << p4 * 3 << endl;
	cout << 0 * p5 << " " << p5 * 5 << endl;

	// test binary operator +
	cout << p4 + p5 << endl << p6 - p7 << endl;
	cout << p8 * p7 << endl;

	myPolynomial tmp1(p4), tmp2, tmp3, tmp4;
	tmp4 = tmp3 = tmp2 = tmp1;
	cout << (tmp1 += p5) << endl;
	cout << (tmp2 -= p5) << endl;
	cout << (tmp3 *= p5) << endl;
	cout << (tmp4 *= 3) << endl;
}
void testDataFromFile()
{
	int numTestCases;
	cin >> numTestCases;
	for (int i = 0; i < numTestCases; i++)
	{
		int numTerms, terms[100];
		/* read first polynomial */
		cin >> numTerms;
		for (int j = 0; j < numTerms; j++)
			cin >> terms[2 * j] >> terms[2 * j + 1];
		myPolynomial p1(numTerms, terms);
		/* read second polynomial */
		cin >> numTerms;
		for (int j = 0; j < numTerms; j++)
			cin >> terms[2 * j] >> terms[2 * j + 1];
		myPolynomial p2(numTerms, terms);
		cout << p1 << endl << p2 << endl;
		cout << p1.getDegree() << " " << p2.getNumTerms() << endl;
		cout << p1.ddx() << endl << p2.ddx() << endl;
		cout << (p1 == p2) << " " << (p1 != p2) << endl;
		cout << p1(1) << endl;
		cout << -p1 + p1 * 2 * p2 - p2 * 2 + 3 * p1 << endl;
		myPolynomial p3(myPolynomial::ZERO), p4(myPolynomial::ONE),
			p5(myPolynomial::X);
		p3 += p1;
		p4 -= p2;
		p5 *= p4;
		p5 *= 2;
		cout << p5 << endl;
	}
}
