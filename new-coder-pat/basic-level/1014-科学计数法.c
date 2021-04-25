#include <stdio.h>
#include <string.h>
int main()
{
    int m, f, i, Id, len;
    char s[9999];
    for (; ~scanf("%s", s);)
    {
        for (len = strlen(s), f = m = Id = 0, i = 3; i < len; s[i] == 'E' ? (s[i++] = '\0', f = 1) : f ? (m = m * 10 + s[i] % 48): (++Id),i++);
        s[0] == '+' ?: printf("-");
        if (s[4 + Id] == '+')
        {
            printf("%c", s[1]);
            if (Id >= m)
                for (--m, i = 3; s[i]; printf(m ? "%c" : "%c.", s[i]), --m, i++);
            else
            {
                for (i = 3; s[i]; --m, printf("%c", s[i]), i++)
                for (; m > 0; printf("0"), --m);
            }
        }
        else
        {
            for (printf("0."), i = 1; i < m; printf("0"), i++)
            for (printf("%c", s[1]), i = 3; s[i]; printf("%c", s[i]), i++);
        }
    }
}

// #include <stdio.h>
// int main()
// {
//     char a[9999];
//     int dot=2,e=0,signa,signb;
//     scanf("%s", a);
//     (a[0]=='+')?:printf("-");
//     int i=1;
//     while (a[i])
//     {
//         if (a[i]=='E')
//         {
//             e=i;
//             signb=(a[i+1]=='+'?0:1);
//         }
//         i++;
//     }

//     return 0;
// }