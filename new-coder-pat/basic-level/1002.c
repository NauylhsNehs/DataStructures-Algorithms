#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    if (n < 1 || n > 1000)
        return 0;
    int A1 = 0, A2 = 0, A2i = 2, A3 = 0, A4 = 0, A4num = 0, A5 = 0;
    for (int i = 0; i < n; i++)
    {
        int e;
        scanf("%d", &e);
        switch (e % 5)
        {
        case 0:
            if (e % 2 == 0)
                A1 += e;
            break;
        case 1:
            A2 += pow(-1, A2i) * e;
            A2i++;
            break;
        case 2:
            A3++;
            break;
        case 3:
            A4 += e;
            A4num++;
            break;
        case 4:
            if (e > A5)
                A5 = e;
            break;
        default:
            break;
        }
    }
    if (A1 > 0)
        printf("%d ", A1);
    else
        printf("N ");
    if (A2 != 0)
        printf("%d ", A2);
    else
        printf("N ");
    printf("%d ", A3);
    if (A4num > 0)
        printf("%.1f ", (float)A4 / A4num);
    else
        printf("N ");
    if (A5 > 0)
        printf("%d", A5);
    else
        printf("N");
    return 0;
}