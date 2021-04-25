#include <stdio.h>
int main()
{
    int n[10], i;
    for (i = 0; i < 10; i++)
        scanf("%d", &n[i]);

    i = 1;
    while (n[i] == 0)
        i++;
    printf("%d", i);
    n[i]--;
    while (n[0])
    {
        printf("0");
        n[0]--;
    }
    for (i; i < 10; i++)
    {
        if (n[i] == 0)
            continue;
        printf("%d", i);
        n[i]--;
        if (n[i] != 0)
            i--;
    }

    return 0;
}