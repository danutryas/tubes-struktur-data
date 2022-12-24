#include "stack_queue.h"
#include <iostream>
using namespace std;

adrQueue createElmtQueue(infotype p)
{
    adrQueue P = new elmtQueue;
    info(P) = p;
    next(P) = NULL;
};

Queue createQueue()
{
    Queue Q;
    Q.head = NULL;
    Q.tail = NULL;
    return Q;
};
Stack createStack()
{
    Stack S;
    S.Top = -1;
    return S;
};

bool isStackFull(Stack S)
{
    if (S.Top == IDXMAX - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
};
bool isStackEmpty(Stack S)
{
    if (S.Top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
};

bool isQueueFull(Queue Q){};
bool isQueueEmpty(Queue Q)
{
    if (Q.head == NULL && Q.tail == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
};

// 1.Insert data (Stack 5, Queue 5)
void Enqueue(Queue &Q, adrQueue P)
{
    if (isQueueEmpty(Q))
    {
        Q.head = P;
        Q.tail = P;
    }
    else
    {
        next(Q.tail) = P;
        Q.tail = P;
    }
};
void Push(Stack &S, infotype P)
{
    if (isStackFull(S))
    {
        cout << "Stack Full" << endl;
    }
    else
    {
        S.Top++;
        S.T[S.Top] = P;
    };
};

// 2.Delete data (Stack 5, Queue 5)
void Dequeue(Queue &Q, adrQueue &P)
{
    if (isQueueEmpty(Q))
    {
        cout << "Queue Kosong" << endl;
    }
    else if (Q.head == Q.tail)
    {
        P = Q.head;
        Q.head = NULL;
        Q.tail = NULL;
    }
    else
    {
        P = Q.head;
        Q.head = next(Q.head);
        next(P) = NULL;
    }
};
void Pop(Stack &S, infotype &P)
{
    if (isStackEmpty(S))
    {
        cout << "Stack Kosong" << endl;
    }
    else
    {
        P = S.T[S.Top];
        S.Top--;
    };
};

// 3.Show data (Stack 5, Queue 5)
void showQueue(Queue Q)
{
    adrQueue P = Q.head;
    while (P != NULL)
    {
        cout << info(P) << endl;
        P = next(P);
    }
};
void showStack(Stack S)
{
    for (int i = 0; i <= S.Top; i++)
    {
        cout << S.T[i] << endl;
    };
};