#include <stdio.h>
int main()
{
    int a, b, d, c[40];
    scanf("%d %d %d", &a, &b, &d);
    int n = a + b;

    int i = 0;
    int j;

    if (n == 0)
    {
        printf("%d", 0);
    }

    while (n != 0)
    {
        c[i++] = n % d;
        n /= d;
    }

    for (j = i - 1; j >= 0; j--)
    {
        printf("%d", c[j]);
    }

    return 0;
}