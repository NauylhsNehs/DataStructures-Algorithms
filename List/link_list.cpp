#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#define ElemType int
#define InitSize 100
#define IncreseSize 10
#define OVERFLOW 1

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

void ShowMean();
LinkList InitList_Head(LinkList &L);
LinkList InitList_Tail(LinkList &L);
int Length(LinkList L);
int LocateElem(LinkList L, ElemType e);
bool GetElem(LinkList L, int i);
// bool ListInsert(LinkList &L, int i, ElemType e);
// bool ListDelete(LinkList &L, int i, ElemType &e);
bool PrintList(LinkList L);
// bool Empty(LinkList L);
// bool DestoryList(LinkList &L);

int main()
{
    int i = 0;
    LinkList L;
    printf("you must init the list first\n");
    while (i == 0)
    {
        if (!L)
            printf("you must init the list first\n");
        int num = 0, e = 0, p = 0;
        ShowMean();
        scanf("%d", &num);
        switch (num)
        {
        case 0:
            i = 1;
            exit(0);
        case 1:
            InitList_Head(L);
            printf("success\n");
            PrintList(L);
            break;
        case 11:
            InitList_Tail(L);
            printf("success\n");
            PrintList(L);
            break;
        case 2:
            printf("the length of the list is %d \n", Length(L));
            break;
        case 3:
            printf("input the elem : ");
            scanf("%d", &e);
            printf("the elem %d is in position %d\n", e, LocateElem(L, e));
            break;
        case 4:
            printf("input the position(from1) : ");
            scanf("%d", &p);
            if (!GetElem(L, p))
            {
                printf("we can't find the elem!\n");
            }
            break;
        // case 5:
        //     printf("input the position(from1) : ");
        //     scanf("%d", &p);
        //     printf("input the elem you wanna to insert : ");
        //     scanf("%d", &e);
        //     if (ListInsert(L, p - 1, e))
        //     {
        //         printf("success\n");
        //     }
        //     else
        //     {
        //         printf("fail to insert!");
        //     }
        //     break;
        // case 6:
        //     printf("input the position(from1) : ");
        //     scanf("%d", &p);
        //     if (ListDelete(L, p - 1, e))
        //     {
        //         printf("the elem you had deleted is %d\n", e);
        //     }
        //     else
        //     {
        //         printf("fail to delete!\n");
        //     }
        //     break;
        case 7:
            PrintList(L);
            printf("success\n");
            break;
        // case 8:
        //     if (Empty(L))
        //         printf("L list is empty\n");
        //     else
        //         printf("L list is not empty\n");
        //     break;
        // case 9:
        //     DestoryList(L);
        //     printf("success\n");
        //     break;
        default:
            printf("please input the right nunber!\n");
            break;
        }
        getch();
        system("cls");
    }
    return 0;
}

void ShowMean()
{
    printf("1.InitList_Head\t11.InitList_Tail\t2.Length\t3.LocateElem\n");
    printf("4.GetElem\t5.ListInsert\t6.ListDelete\t7.PrintList\n");
    printf("8.Empty\t9.DestoryList\t0.quit\n");
}

LinkList InitList_Head(LinkList &L)
{
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode)); //头结点
    if (!L)
        exit(OVERFLOW);
    L->next = NULL;
    printf("please input the elems : \n\(99 for default, 999 for exit\)\n");
    scanf("%d", &x);
    if (x == 99)
    {
        for (int i = 4; i >= 0; i--)
        {
            s = (LNode *)malloc(sizeof(LNode));
            if (!s)
                exit(OVERFLOW);
            s->data = i;
            s->next = L->next;
            L->next = s;
        }
        return L;
    }
    while (x != 999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        if (!s)
            exit(OVERFLOW);
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}
LinkList InitList_Tail(LinkList &L)
{

    LNode *s;
    LNode *r = L; //指向表尾
    int x;
    L = (LinkList)malloc(sizeof(LNode)); //头结点
    if (!L)
        exit(OVERFLOW);
    L->next = NULL;
    printf("please input the elems : \n\(99 for default, 999 for exit\)\n");
    scanf("%d", &x);
    if (x == 99)
    {
        for (int i = 0; i < 5; i++)
        {
            s = (LNode *)malloc(sizeof(LNode));
            if (!s)
                exit(OVERFLOW);
            s->data = i;
            r->next = s;
            r = s;
        }
        r->next = NULL;
        return L;
    }
    while (x != 999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        if (!s)
            exit(OVERFLOW);
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL; //尾节点置空
    return L;
}
int Length(LinkList L)
{
    int len = 0;
    L = L->next;
    while (L)
    {
        len++;
        L = L->next;
    }
    return len;
}
int LocateElem(LinkList L, ElemType e)
{
    L = L->next;
    int len = Length(L);
    for (int i = 0; i < len; i++)
    {
        if (L->data == e)
            return i + 1;
        else
            L = L->next;
    }
    return 999;
}
bool GetElem(LinkList L, int i)
{
    L = L->next;
    int len = Length(L);
    if (i <= 0 || i > len)
        return false;
    for (int j = 0; j < len; j++)
    {
        if (j == i - 1)
        {
            printf("the elem in position %d is %d \n", i, L->data);
            return true;
        }
        L = L->next;
    }
    return false;
}
bool PrintList(LinkList L)
{
    L = L->next;
    while (L)
    {
        printf("%d ", L->data);
        L = L->next;
    }
    return true;
}