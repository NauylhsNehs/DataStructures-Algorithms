#include <stdio.h>
#include <stdlib.h>
#define Status int
#define TRUE 1
#define FALSE 0
#define ElemType int
#define InitSize 100
#define IncreseSize 10
#define OVERFLOW 1

typedef struct
{
    ElemType *data;
    int size, length;
} SqList;

Status InitList(SqList *L);
Status Length(SqList L);
Status LocateElem(SqList L, ElemType e);
Status GetElem(SqList L, int i);
Status ListInsert(SqList *L, int i, ElemType e);
Status ListDelete(SqList *L, int i, ElemType *e);
Status PrintList(SqList L);
Status Empty(SqList L);
Status DestoryList(SqList *L);

void main()
{
    SqList L;
    InitList(&L);
    PrintList(L);
}

void ShowMean()
{
    printf("1.\t2.\t3.\t4.\n");
}
Status InitList(SqList *L)
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
    return TRUE;
}
Status Length(SqList L)
{
    return TRUE;
}
Status LocateElem(SqList L, ElemType e)
{
    return TRUE;
}
Status GetElem(SqList L, int i)
{
    return TRUE;
}
Status ListInsert(SqList *L, int i, ElemType e)
{
    return TRUE;
}
Status ListDelete(SqList *L, int i, ElemType *e)
{
    return TRUE;
}
Status PrintList(SqList L)
{
    printf("the data is : ");
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
    printf("\n");
    return TRUE;
}
Status Empty(SqList L)
{
    return TRUE;
}
Status DestoryList(SqList *L)
{
    return TRUE;
}