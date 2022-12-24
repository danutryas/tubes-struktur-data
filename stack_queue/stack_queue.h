#ifndef STACK_QUEUE_H_INCLUDED
#define STACK_QUEUE_H_INCLUDED
#include <iostream>
using namespace std;

#define next(P) (P)->next
#define info(P) (P)->info

typedef char infotype;

// stack dengan array
const int IDXMAX = 4;
typedef struct Stack
{
    infotype T[IDXMAX];
    int Top;
};

Stack createStack();

bool isStackFull(Stack S);
bool isStackEmpty(Stack S);
// 1.Insert data (Stack 5, Queue 5)
void Push(Stack &S, infotype P);
// 2.Delete data (Stack 5, Queue 5)
void Pop(Stack &S, infotype &P);
// 3.Show data (Stack 5, Queue 5)
void showStack(Stack S);
// 4.Pemanfaatan primitif dalam penyelesaian masalah, Contoh: infix to prefix dan kasus lainnya. (Stack 30, Queue 30)
// 5.Main program (10)

// queue dengan list
typedef struct elmtQueue *adrQueue;

typedef struct elmtQueue
{
    infotype info;
    adrQueue next;
};

typedef struct Queue
{
    adrQueue head, tail;
};

Queue createQueue();

bool isQueueFull(Queue Q);
bool isQueueEmpty(Queue Q);

// create element
adrQueue createElmtQueue(infotype p);

// 1.Insert data (Stack 5, Queue 5)
void Enqueue(Queue &Q, adrQueue P);
void Push(Stack &S, infotype P);

// 2.Delete data (Stack 5, Queue 5)
void Dequeue(Queue &Q, adrQueue &P);
void Pop(Stack &S, infotype &P);

// 3.Show data (Stack 5, Queue 5)
void showQueue(Queue Q);
void showStack(Stack S);

// 4.Pemanfaatan primitif dalam penyelesaian masalah, Contoh: infix to prefix dan kasus lainnya. (Stack 30, Queue 30)
// 5.Main program (10)

#endif // STACK_QUEUE_H_INCLUDED
