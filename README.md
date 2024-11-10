# DataStructure

### 개요
이 저장소는 **2023-1학기 자료구조** 수업에서 송영록 교수님께서 강의하신 내용을 바탕으로 작성된 코드입니다. 자료구조와 알고리즘의 기본 개념을 학습하고 이를 코드로 구현한 내용을 포함하고 있습니다.

### 프로젝트 구성
이 저장소는 다음과 같은 자료구조 및 알고리즘을 구현한 파일들로 구성되어 있습니다. 각 파일에는 특정 자료구조 및 알고리즘을 연습하고 테스트할 수 있는 코드가 포함되어 있습니다.

### 파일 설명

- **연결 리스트 (Linked List)**
  - `LinkedList.cpp`: 연결 리스트의 기본 구현
  - `DoubleLinkedList.cpp`: 이중 연결 리스트 구현
  - `SinglyLinkedList-Head.cpp`, `SinglyLinkedList-Tail.cpp`: 헤드와 테일을 사용하는 단일 연결 리스트 구현
  - `arrayLinkedList.cpp`: 배열을 이용한 연결 리스트 구현
  - `circleLinkedList.cpp`: 원형 연결 리스트 구현
  - `linkedlistpractice.cpp`: 연결 리스트 연습 문제 코드

- **스택과 큐 (Stack & Queue)**
  - `Stack.cpp`: 스택 구현
  - `Queue.cpp`: 큐 구현
  - `CircleQueue.cpp`: 원형 큐 구현
  - `DequePractice.cpp`, `Dequeue-palindrome.cpp`, `Dequeue.cpp`: 덱(Deque) 연습 문제와 팔린드롬 검사 구현

- **트리 (Tree)**
  - `Tree-InsertNode.cpp`: 트리에 노드를 삽입하는 코드
  - `Tree-Order.cpp`: 트리 순회 방법 (전위, 중위, 후위 순회)
  - `Level-Iter-Order.cpp`: 트리의 레벨 순회 및 반복 순회
  - `tree.cpp`: 트리 기본 구현 및 연습 문제 코드

- **그래프 (Graph)**
  - `Graph-adjacencyList.cpp`, `Graph-adgacencyMatrix.cpp`: 인접 리스트와 인접 행렬을 이용한 그래프 구현
  - `Graph-1.cpp`, `Graph-2.cpp`: 그래프 관련 다양한 문제 구현
  - `Dijkstra-Floyd.cpp`: 다익스트라 및 플로이드 알고리즘을 통한 최단 경로 탐색
  - `Kruskal.cpp`: 크루스칼 알고리즘을 통한 최소 신장 트리 생성
  - `Prim.cpp`: 프림 알고리즘을 통한 최소 신장 트리 생성

- **정렬 (Sorting)**
  - `sort.cpp`, `sort-1.cpp`, `sort-2.cpp`: 다양한 정렬 알고리즘 구현 및 비교

- **기타 연습 문제**
  - `BinarySearch.cpp`: 이진 탐색 구현
  - `myPolynomial.cpp`: 다항식 연산 예제
  - `Matrix.cpp`: 행렬 연산과 관련된 예제

### 사용법
각 파일은 독립적으로 실행할 수 있으며, 특정 자료구조나 알고리즘을 테스트하는 데 사용됩니다.

1. 이 저장소를 클론합니다.
   ```bash
   git clone https://github.com/706-Camille/DataStructure.git
   cd DataStructure
