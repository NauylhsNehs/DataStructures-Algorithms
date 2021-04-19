#include<stdio.h>
int main()
{
    char a[10],b[10];
    int da,db;
    int i,s,pa=0,pb=0;
    scanf("%s %d %s %d",a,&da,b,&db);
    // printf("%s %d %s %d\n",a,da,b,db);
    for (i = 0,s=1; a[i]; i++)
    {
        // printf("%d %d\n",a[i],a[i]-'0');
        if (a[i]-'0'==da)
        {
            pa+=da*s;
            s=s*10;
        }
    }
    for (i = 0,s=1; b[i]; i++)
    {
        // printf("%d %d\n",b[i],b[i]-'0');
        if (b[i]-'0'==db)
        {
            pb+=db*s;
            s=s*10;
        }
    }
    // printf("\n%d %d",pa,pb);
    printf("%d",pa+pb);
    return 0;
}