#include <stdio.h>
typedef struct yuebing
{
    int storage;
    int price;
    float unit;
} YB;
int main()
{
    int N, D;
    YB array[1000] = {0}, tmp;
    scanf("%d%d", &N, &D);
    int i, j;
    float sum = 0;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &array[i].storage);
    }
    for (i = 0; i < N; i++)
    {
        scanf("%d", &array[i].price);
        array[i].unit = 1.0 * array[i].price / array[i].storage;
    }
    for (i = 0; i < N - 1; i++)
    {
        for (j = N - 1; j >= i + 1; j--)
        {
            if (array[j - 1].unit < array[j].unit)
            {
                tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
            }
        }
    }
    i = 0;
    while (D != 0 && i < N)
    {
        if (array[i].storage >= D)
        {
            sum += array[i].unit * D;
            break;
        }
        else
        {
            D -= array[i].storage;
            sum += array[i].price;
            i++;
        }
    }

    printf("%.2f\n", sum);
    return 0;
}
