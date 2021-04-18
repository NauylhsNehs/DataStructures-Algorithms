#include <stdio.h>
#include <math.h>
int main()
{
    int M, N;
    int i, j;
    int count = 1;
    int n = 0;
    int a[10000];
    a[0] = 1;
    scanf("%d %d", &M, &N);
    for (i = 1; i <= N; i++)
    {
        a[i] = a[i - 1] + 1;
        for (j = 2; j <= sqrt(a[i]); j++)
        {
            if (a[i] % j == 0)
            {
                a[i]++;
                j = 1;
            }
        }
    }
    for (i = M; i < N; i++)
        printf((count++ % 10) ? "%d " : "%d\n", a[i]);
    printf("%d", a[N]);

    return 0;
}