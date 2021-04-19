#include <stdio.h>
int main()
{
    char a[60], b[60], c[60], d[60];
    scanf("%s %s %s %s", a, b, c, d);
    char *day[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int i, j, count = 0;
    // char result[]={"day","hour","minute"};
    char result[3];
    for (i = 0; i < 60; i++)
    {
        if (!a[i] || !b[i] || count == 2)
        {
            break;
        }
        if (count==0)
        {
            if (a[i] < 'A' || a[i] > 'Z')
            {
                continue;
            }

            if (a[i] == b[i])
            {
                result[count++] = a[i];
                continue;
            }
        }
        if (count==1)
        {
            if (a[i] == b[i])
            {
                result[count++] = a[i];
            }
        }
        
        
    }
    for (i = 0; i < 60; i++)
    {
        if (!c[i] || !d[i])
        {
            break;
        }
        if (c[i] < 'A' || (c[i] > 'Z' && c[i] < 'a') || c[i] > 'z')
        {
            continue;
        }
        if (c[i] == d[i])
        {
            result[2] = c[i];
            break;
        }
    }
    printf("%c %c %c\n", result[0], result[1], result[2]);
    printf("%s ", day[(int)(result[0] - 'A')]);
    if (result[1]<='9'&&result[1]>='0')
    {
        printf("%02d:",result[1]-'0');
    }
    else
    {
        printf("%02d:", result[1]-'A'+10);
    }
    printf("%02d", i);
    return 0;
}