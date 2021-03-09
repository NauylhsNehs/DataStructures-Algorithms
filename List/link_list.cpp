#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElemType int
#define InitSize 100
#define IncreseSize 10
#define OVERFLOW 1

typedef struct
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

void ShowMean();
bool InitList(LinkList *L);
bool InitListt(LinkList *L);
bool Length(LinkList L);
int LocateElem(LinkList L, ElemType e);
bool GetElem(LinkList L, int i);
bool ListInsert(LinkList *L, int i, ElemType e);
bool ListDelete(LinkList *L, int i, ElemType *e);
bool PrintList(LinkList L);
bool Empty(LinkList L);
bool DestoryList(LinkList *L);

// void main()
// {
//     int i = 0;
//     LinkList L;
//     // InitListt(&L);
//     while (i == 0)
//     {
//         if (!L.data)
//             printf("you must init the list first\n");
//         int num = 0, e = 0, p = 0;
//         ShowMean();
//         scanf("%d", &num);
//         switch (num)
//         {
//         case 0:
//             i = 1;
//             exit(0);
//         case 1:
//             InitList(&L);
//             printf("suceess\n");
//             break;
//         case 2:
//             Length(L);
//             printf("suceess\n");
//             break;
//         case 3:
//             printf("input the elem : ");
//             scanf("%d", &e);
//             printf("the elem %d is in position %d\n", e, LocateElem(L, e));
//             break;
//         case 4:
//             printf("input the position(from1) : ");
//             scanf("%d", &p);
//             GetElem(L, p);
//             printf("suceess\n");
//             break;
//         case 5:
//             printf("input the position(from1) : ");
//             scanf("%d", &p);
//             printf("input the elem you wanna to insert : ");
//             scanf("%d", &e);
//             if (ListInsert(&L, p - 1, e))
//             {
//                 printf("suceess\n");
//             }
//             else
//             {
//                 printf("fail to insert!");
//             }
//             break;
//         case 6:
//             printf("input the position(from1) : ");
//             scanf("%d", &p);
//             if (ListDelete(&L, p - 1, &e))
//             {
//                 printf("the elem you had deleted is %d\n", e);
//             }
//             else
//             {
//                 printf("fail to delete!\n");
//             }
//             break;
//         case 7:
//             PrintList(L);
//             printf("suceess\n");
//             break;
//         case 8:
//             if (Empty(L))
//                 printf("L list is empty\n");
//             else
//                 printf("L list is not empty\n");
//             break;
//         case 9:
//             DestoryList(&L);
//             printf("suceess\n");
//             break;
//         default:
//             printf("please input the right nunber!\n");
//             break;
//         }
//         getch();
//         system("cls");
//     }
// }

void ShowMean()
{
    printf("1.InitList\t2.Length\t3.LocateElem\t4.GetElem\n");
    printf("5.ListInsert\t6.ListDelete\t7.PrintList\t8.Empty\n");
    printf("9.DestoryList\t0.quit\n");
}

bool InitList(LinkList *L)
{
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode)); //头结点
    if (!L)
        exit(OVERFLOW);
    (*L)->next = NULL;
    printf("please input the elems : \n\(99 for default, 999 for exit\)\n");
    scanf("%d", &x);
    if (x == 99)
    {
        return true;
    }
    while (x != 999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        if (!s)
            exit(OVERFLOW);
        s->data = x;
        s->next = (*L)->next;
        (*L)->next = s;
        scanf("%d", &x);
    }
    return true;
}