#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#define ElemType int
#define InitSize 100
#define IncreseSize 10
#define OVERFLOW 1
#define MAXSIZE 50

// Static link list 
// thinking......
typedef struct SNode
{
    ElemType data;
    int next;
} SLinkList[MAXSIZE];
bool InitList(SLinkList &L);
bool ListInsert(SLinkList &L, int i, ElemType e);
bool ListDelete(SLinkList &L, int i, ElemType &e);

// --------------------------------------------------
// --------------------------------------------------

// Doubly linked list
typedef struct DNode
{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
} DNode, *DLinkList;
DNode *GetDNodeElem(DLinkList L, int i);
int Length(DLinkList L);
bool ListInsert(DLinkList &L, int i, ElemType e)
{
    if (i > Length(L) || i <= 0)
        return false;
    DNode *p = GetDNodeElem(L, i - 1);
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->next = p->next;

    s->prior = p;
    p->next->prior = s;
    p->next = s;
    return true;
}
bool ListDelete(DLinkList &L, int i, ElemType &e)
{
    if (i > Length(L) || i <= 0)
        return false;
    DNode *s = GetDNodeElem(L, i);
    s->prior->next = s->next;
    s->next->prior = s->prior;
    free(s);
    return true;
}

// --------------------------------------------------
// --------------------------------------------------

// Singly Circular linked list
typedef struct CNode
{
    ElemType data;
    struct CNode *next;
} CNode, *CLinkList;
int Length(CLinkList L);
bool InitList(CLinkList &L)
{
    L = (CLinkList)malloc(sizeof(struct CNode)); //设立尾指针
    if (!L)
        exit(OVERFLOW);
    L->next = L; //指向头结点
    return true;
}
bool ListInsert(CLinkList &L, int i, ElemType e)
{                       //后插
    CNode *p = L->next; //找到头结点
    CNode *s = (CNode *)malloc(sizeof(CNode));
    int j = 1;
    if (i > Length(L) + 1 || i <= 0)
        return false;
    while (j < i - 1)
    { //找到第i-1个结点
        p = p->next;
        j++;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    if (p == L)
        L = s; // 使尾结点仍为L
    return true;
}
bool ListDelete(CLinkList &L, int i, ElemType &e)
{
    CNode *p = L->next;
    CNode *q;
    int j = 1;
    if (i > Length(L) || i <= 0)
        return false;
    while (j < i - 1)
    {
        p = p->next;
        j++;
    }
    q = p->next;
    e = q->data;
    p->next = q->next;
    if (q == L)
        L = p;
    free(q);
    return true;
}