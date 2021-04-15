#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        long a = 0, b = 0, c = 0;
        scanf("%ld %ld %ld", &a, &b, &c);
        printf("Case #%d: %s\n", i + 1, (a + b) > c ? "true" : "false");
    }
    return 0;
}