#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#define ElemType int
#define InitSize 100
#define IncreseSize 10
#define OVERFLOW 1

// Static link list
typedef struct SNode
{
    ElemType data;
    struct SNode *next;
} SNode, *SLinkList;
SNode *GetSNodeElem(SLinkList L, int i);
bool ListInsert(SLinkList &L, int i, ElemType e)
{
    SNode *p = GetSNodeElem(L, i - 1);
    SNode *s = (SNode *)malloc(sizeof(SNode));
    s->next = p->next;
}
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
DNode *GetDNodeElem(SLinkList L, int i);
bool ListInsert(SLinkList &L, int i, ElemType e)
{
    DNode *p = GetDNodeElem(L, i-1);
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->next = p->next;
    s->prior = p;
    p->next->prior = s;
    p->next = s;
}
bool ListDelete(SLinkList &L, int i, ElemType &e)
{
    DNode *s = GetDNodeElem(L, i);
    s->prior->next=s->next;
    s->next->prior=s->prior;
    free(s);
}

// --------------------------------------------------
// --------------------------------------------------

// Circular linked list
typedef struct CNode
{
    ElemType data;
    struct CNode *next;
} CNode, *CLinkList;
CNode *GetCNodeElem(SLinkList L, int i);
bool ListInsert(SLinkList &L, int i, ElemType e)
{
    CNode *s = GetCNodeElem(L, i);
}
bool ListDelete(SLinkList &L, int i, ElemType &e);