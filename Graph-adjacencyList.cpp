#include <stdio.h>
#include <stdlib.h>

#define N 10
#define TRUE 1
#define FALSE 0


typedef int element;
/* -------------------------------- */
typedef struct
{
    element data[N];
    int top;
}StackType;

void initStack(StackType* S)
{
    S->top = -1;
}

int isStackEmpty(StackType* S)
{
    return S->top == -1;
}

int isStackFull(StackType* S)
{
    return S->top == N - 1;
}

void push(StackType* S, element d)
{
    if (isStackFull(S))
        printf("Overflow!!\n");
    else
    {
        S->top++;
        S->data[S->top] = d;
    }
}

element pop(StackType* S)
{
    if (isStackEmpty(S))
    {
        printf("Empty!!\n");
        return -1;
    }
    element d = S->data[S->top];
    S->top--;
    return d;
}

element peek(StackType* S)
{
    if (isStackEmpty(S))
    {
        printf("Empty!!\n");
        return -1;
    }
    return S->data[S->top];
}

/* -------------------------------- */

typedef struct
{
    element data[N];
    int front, rear;
}QueueType;

void initQueue(QueueType* Q)
{
    Q->front = Q->rear = 0;
}

int isQueueEmpty(QueueType* Q)
{
    return Q->rear == Q->front;
}

int isQueueFull(QueueType* Q)
{
    return (Q->rear + 1) % N == Q->front;
}


void enqueue(QueueType* Q, element d)
{
    if (isQueueFull(Q))
        printf("Overflow!!\n");
    else
    {
        Q->rear = (Q->rear + 1) % N;
        Q->data[Q->rear] = d;
    }
}

element dequeue(QueueType* Q)
{
    if (isQueueEmpty(Q))
    {
        printf("Empty!!\n");
        return -1;
    }
    Q->front = (Q->front + 1) % N;
    return Q->data[Q->front];
}

/* -------------------------------- */

typedef struct IncidentEdge
{
    char aName;
    struct IncidentEdge* next;
}IncidentEdge;

typedef struct Vertex
{
    char vName;
    int isVisit;
    IncidentEdge* iHead;
    struct Vertex* next;
}Vertex;

typedef struct
{
    Vertex* vHead;

}GraphType;

void init(GraphType* G)
{
    G->vHead = NULL;
}

void makeVertex(GraphType* G, char vName)
{
    Vertex* v = (Vertex*)malloc(sizeof(Vertex));
    v->vName = vName;
    v->isVisit = FALSE;
    v->iHead = NULL;
    v->next = NULL;
    Vertex* p = G->vHead;

    if (p == NULL)
        G->vHead = v;

    else
    {
        while (p->next != NULL)
            p = p->next;
        p->next = v;
    }

}

void makeIncidentEdge(Vertex* v, char aName)
{

    IncidentEdge* p = (IncidentEdge*)malloc(sizeof(IncidentEdge));

    p->aName = aName;
    p->next = NULL;
    IncidentEdge* q = v->iHead;

    if (q == NULL)
        v->iHead = p;
    else

    {

        while (q->next != NULL)
            q = q->next;

        q->next = p;

    }
}



Vertex* findVertex(GraphType* G, char vName)

{

    Vertex* v = G->vHead;

    while (v->vName != vName)
        v = v->next;

    return v;

}

void insertEdge(GraphType* G, char v1, char v2)
{
    Vertex* v = findVertex(G, v1);
    makeIncidentEdge(v, v2);

    v = findVertex(G, v2);
    makeIncidentEdge(v, v1);
}

void rDFS(GraphType* G, char vName)
{
    Vertex* v = findVertex(G, vName);
    IncidentEdge* p;

    if (v->isVisit == FALSE)
    {
        v->isVisit = TRUE;
        printf("[%c] ", v->vName);
    }

    for (p = v->iHead; p != NULL; p = p->next)
    {
        v = findVertex(G, p->aName);
        if (v->isVisit == FALSE)
            rDFS(G, v->vName);
    }

}

void iDFS(GraphType* G, char vName)
{
    Vertex* v = findVertex(G, vName);
    IncidentEdge* p;
    
    StackType S;
    initStack(&S);

    push(&S, v->vName);

    while (!isStackEmpty(&S))
    {
        v = findVertex(G, peek(&S));
        if (v->isVisit == FALSE)
        {
            v->isVisit = TRUE;
            printf("[%c] ", v->vName);
        }

        for (p = v->iHead; p != NULL; p = p->next)
        {
            v = findVertex(G, p->aName);
            if (v->isVisit == FALSE)
            {
                push(&S, v->vName);
                break;
            }
        }

        if (p == NULL)
            pop(&S);
    }
}

void BFS(GraphType* G, char vName)
{
    Vertex* v = findVertex(G, vName);
    IncidentEdge* p;

    QueueType Q;
    initQueue(&Q);

    v->isVisit = TRUE;
    printf("[%c] ", v->vName);
    enqueue(&Q, v->vName);

    while (!isQueueEmpty(&Q))
    {
        v = findVertex(G, dequeue(&Q));

        for (p = v->iHead; p != NULL; p = p->next)
        {
            v = findVertex(G, p->aName);

            if (v->isVisit == FALSE)
            {
                v->isVisit = TRUE;
                printf("[%c] ", v->vName);
                enqueue(&Q, v->vName);
            }
        }

    }
}

void print(GraphType* G)
{
    Vertex* p = G->vHead;
    IncidentEdge* q;

    for (; p != NULL; p = p->next)
    {
        printf("[%c] : ", p->vName);
        for (q = p->iHead; q != NULL; q = q->next)
            printf("[%c] ", q->aName);

        printf("\n");
    }
}

int main()
{
    GraphType G;
    init(&G);
    makeVertex(&G, 'a'); makeVertex(&G, 'b'); makeVertex(&G, 'c');
    makeVertex(&G, 'd'); makeVertex(&G, 'e'); makeVertex(&G, 'f');
    makeVertex(&G, 'g');

    insertEdge(&G, 'a', 'b'); insertEdge(&G, 'a', 'f');
    insertEdge(&G, 'b', 'c'); insertEdge(&G, 'b', 'g');
    insertEdge(&G, 'c', 'd');
    insertEdge(&G, 'd', 'e'); insertEdge(&G, 'd', 'g');
    insertEdge(&G, 'e', 'f'); insertEdge(&G, 'e', 'g');
    //insertEdge(&G, 'a', 'b'); insertEdge(&G, 'a', 'c');
    //insertEdge(&G, 'a', 'd'); insertEdge(&G, 'b', 'c');
    //insertEdge(&G, 'b', 'e'); insertEdge(&G, 'd', 'e');



    print(&G); printf("\n");

    printf("rDFS : "); rDFS(&G, 1);

    //printf("iDFS : "); iDFS(&G, 1);

    //printf("BFS : "); BFS(&G, 7);



    return 0;

}