#include <stdio.h>
#include <string.h>
int main()
{
    char str[1000];
    scanf("%s", str);
    int number[10] = {0};
    int i;
    for (i = 0; i < strlen(str); i++)
    {
        number[str[i] - '0']++;
    }
    for (i = 0; i < 10; i++)
    {
        if (number[i] != 0)
        {
            printf("%d:%d\n", i, number[i]);
        }
    }
    return 0;
}