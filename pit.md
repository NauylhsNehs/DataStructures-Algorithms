. 直接成员访问操作符 结构体用
-> 间接成员访问操作符 结构体的指针用
（*a）.b 等价于 a->b

exit(0) 正常退出 
exit(其他) 异常退出
返回给操作系统

system("cls");  清屏

int getc(FILE *stream); 
int getchar(void); 
int getch();
int getche(void); 

Option 1 (C99 and newer)
    #include <stdbool.h>
Option 2
    typedef enum { false, true } bool;
Option 3
    typedef int bool;
    enum { false, true };
Option 4
    typedef int bool;
    #define true 1
    #define false 0

malloc realloc calloc free

结构体变量.成员名
(*指针变量).成员名
指针变量->成员名