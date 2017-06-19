#include <stdio.h>
#include <stdlib.h>
#include "log.h"
#define FUNC(a) printf("The area is #a is %d\n",(a)*(a));
#define FUNC1(a) printf("The area is "#a" is %d\n",(a)*(a));//#用在预编译语句里面可以把预编译函数的变量直接格式成字符串
#define FUNC2(a) printf("The area is "#a" is %d\n",##x);//## 是宏连接符，作变量链接
#define Debug(...) printf(##__VA_ARGS__);//__VA_ARGS__是可变参数宏
#define FUN_CPRINT(i,col,log,cont,...) fprintf(log,cont,##__VA_ARGS__);
#define FUN_DEBUG_CPRINT(i,col,cont,...)	FUN_CPRINT(i,col,cont,##__VA_ARGS__)
#define MARCO(...) printf(##__VA_ARGS__);
int main()
{
    int x=900;
    FILE *file;
    if((file=fopen("log.dat","w+"))==NULL){
        exit(0);
    }
    FUN_DEBUG_CPRINT(1,2,file,"hello=%d,%d",3,3)
    MARCO("MARCO\n")
    LOG("hello=%d,%d\n",3,3);
    FUNC(30)
    FUNC1(30)
    FUNC2(30)
    Debug("hello\n")
    printf("Hello, World!\n");
    return 0;
}
