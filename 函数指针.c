#include <stdio.h>
void func(int, int);
void caller(void(*p)(int, int));
int main()
{
    void(*p)(int, int);
    p=func;
    caller(p);

    printf("Hello, World!\n");
    return 0;
}
void func(int i,int j) {
    printf("%d",1);

}
void caller(void(*p)(int, int)) {
    func(1,2);
}
