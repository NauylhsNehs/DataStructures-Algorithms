#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElemType int
#define InitSize 100
#define IncreseSize 10
#define OVERFLOW 1

typedef struct
{
    ElemType *data;
    int size, length;
} SqList;

void ShowMean();
bool InitList(SqList *L);
bool InitListt(SqList *L);
bool Length(SqList L);
int LocateElem(SqList L, ElemType e);
bool GetElem(SqList L, int i);
bool ListInsert(SqList *L, int i, ElemType e);
bool ListDelete(SqList *L, int i, ElemType *e);
bool PrintList(SqList L);
bool Empty(SqList L);
bool DestoryList(SqList *L);

void main()
{
    int i = 0;
    SqList L;
    // InitListt(&L);
    while (i == 0)
    {
        if (!L.data)printf("you must init the list first\n");
        int num = 0, e = 0, p = 0;
        ShowMean();
        scanf("%d", &num);
        switch (num)
        {
        case 0:
            i = 1;
            exit(0);
        case 1:
            InitList(&L);
            printf("suceess\n");
            break;
        case 2:
            Length(L);
            printf("suceess\n");
            break;
        case 3:
            printf("input the elem : ");
            scanf("%d", &e);
            printf("the elem %d is in position %d\n", e, LocateElem(L, e));
            break;
        case 4:
            printf("input the position(from1) : ");
            scanf("%d", &p);
            GetElem(L, p);
            printf("suceess\n");
            break;
        case 5:
            printf("input the position(from1) : ");
            scanf("%d", &p);
            printf("input the elem you wanna to insert : ");
            scanf("%d", &e);
            if (ListInsert(&L, p - 1, e))
            {
                printf("suceess\n");
            }
            else
            {
                printf("fail to insert!");
            }
            break;
        case 6:
            printf("input the position(from1) : ");
            scanf("%d", &p);
            if (ListDelete(&L, p-1, &e))
            {
                printf("the elem you had deleted is %d\n", e);
            }
            else
            {
                printf("fail to delete!\n");
            }
            break;
        case 7:
            PrintList(L);
            printf("suceess\n");
            break;
        case 8:
            if(Empty(L))printf("L list is empty\n");
            else printf("L list is not empty\n");
            break;
        case 9:
            DestoryList(&L);
            printf("suceess\n");
            break;
        default:
            printf("please input the right nunber!\n");
            break;
        }
        getch();
        system("cls");
    }
}

void ShowMean()
{
    printf("1.InitList\t2.Length\t3.LocateElem\t4.GetElem\n");
    printf("5.ListInsert\t6.ListDelete\t7.PrintList\t8.Empty\n");
    printf("9.DestoryList\t0.quit\n");
}
bool InitList(SqList *L)
{
    L->data = (ElemType *)malloc(IncreseSize * sizeof(ElemType));
    L->size = InitSize;
    if (!L->data)
        exit(OVERFLOW);
    int nums = 0;
    printf("How many numbers do you wanna to input? : ");
    scanf("%d", &nums);
    if (nums == 0)
    {
        for (int i = 0; i < 5; i++)
        {
            L->data[i] = i;
            L->length++;
        }
    }
    else
    {
        printf("please input %d numbers: ", nums);
        int j = 0;
        for (int i = 0; i < nums; i++)
        {
            scanf("%d", &j);
            L->data[i] = j;
            L->length++;
        }
    }
    printf("\n");
    return true;
}
bool InitListt(SqList *L)
{
    L->data = (ElemType *)malloc(InitSize * sizeof(ElemType));
    L->size = InitSize;
    if (!L->data)
        exit(OVERFLOW);
    for (int i = 0; i < 5; i++)
    {
        L->data[i] = i;
        L->length++;
    }
    printf("init success\n");
    return true;
}
bool Length(SqList L)
{
    printf("the length of L list is : %d\n", L.length);
    return true;
}
int LocateElem(SqList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}
bool GetElem(SqList L, int i)
{
    printf("the elem %d is in the position %d\n", L.data[i - 1], i);
    return true;
}
bool ListInsert(SqList *L, int i, ElemType e)
{
    if (i < 0 || i >= L->length)
        return false;
    if (L->length >= L->size)
    {
        L->data = (ElemType *)realloc(L->data, (L->size + IncreseSize) * sizeof(ElemType));
        if (!L->data)
            exit(OVERFLOW);
        L->size += IncreseSize;
    }
    for (int j = L->length - 1; j >= i; j--)
        L->data[j + 1] = L->data[j];
    L->data[i] = e;
    L->length++;
    return true;
}
bool ListDelete(SqList *L, int i, ElemType *e)
{
    if (i < 0 || i >= L->length)
    {
        return false;
    }
    e=L->data[i];
    for (int j = i; j < L->length-1; j++)
        L->data[j]=L->data[j+1];
    L->length--;
    return true;
}
bool PrintList(SqList L)
{
    printf("the data is : ");
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
    printf("\n");
    return true;
}
bool Empty(SqList L)
{
    if (L.length<=0)return true;
    return false;
}
bool DestoryList(SqList *L)
{
    free(L->data);
    L->data=NULL;
    L->length=0;
    L->size=0;
    printf("L list is deleting\n");
    return true;
}