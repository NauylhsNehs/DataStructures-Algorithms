#include <stdio.h>
int main()
{
    int n, i;
    char jia, yi;
    int j[3] = {0, 0, 0}, y[3] = {0, 0, 0};
    int jw[3] = {0, 0, 0}, yw[3] = {0, 0, 0};

    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
    {
        scanf("%c %c", &jia, &yi);
        switch (jia - yi)
        {
        case 0:
            j[1]++;
            y[1]++;
            break;
        case -1:
            j[0]++;
            y[2]++;
            jw[0]++;
            break;
        case -7:
            j[0]++;
            y[2]++;
            jw[1]++;
            break;
        case 8:
            j[0]++;
            y[2]++;
            jw[2]++;
            break;
        case -8:
            j[2]++;
            y[0]++;
            yw[2]++;
            break;
        case 1:
            j[2]++;
            y[0]++;
            yw[0]++;
            break;
        case 7:
            j[2]++;
            y[0]++;
            yw[1]++;
            break;
        default:
            break;
        }
        getchar();
    }
    printf("%d %d %d\n", j[0], j[1], j[2]);
    printf("%d %d %d\n", y[0], y[1], y[2]);
    int jf = 0, yf = 0;

    char bcj[3] = {'B', 'C', 'J'};
    if (jw[0] < jw[1])
    {
        jf = jw[1];
        i = 1;
    }
    else
    {
        jf = jw[0];
        i = 0;
    }
    if (jf < jw[2])
        printf("J");
    else
        printf("%c ", bcj[i]);
    if (yw[0] < yw[1])
    {
        yf = yw[1];
        i = 1;
    }
    else
    {
        yf = yw[0];
        i = 0;
    }
    if (yf < yw[2])
        printf("J");
    else
        printf("%c", bcj[i]);

    return 0;
}