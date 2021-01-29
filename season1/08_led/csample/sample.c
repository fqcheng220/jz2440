
#include<stdio.h>

void pointerTest();
int main()
{
    unsigned int    *p  = (unsigned int *)

                          malloc(sizeof(unsigned int));
    *p                  = 0xfffffffe;
    unsigned int    i1  = 0;

    if (i1 == 0)
    {
        printf("yes it's %d\n", i1);
    }

    unsigned int    i2  = 1;

    if (i2 == 1)
    {
        printf("yes it's %d\n", i2);
    }

    unsigned int    tmp = *p;
    unsigned int    tmp2 = 1 << 0;

    printf("result = %d \n", (tmp & tmp2) == 0);

    if ((*p & 1 << 0) == 0)
    {
        printf("equals 0 \n");
    }
    else
    {
        printf("not equals 0 \n");

    }

    unsigned int    iTest  = 0xffffffff;
    printf("before %d \n", iTest);
    iTest &= ~(1 << 4);
    printf("after %d \n", iTest);

    pointerTest();
}

void pointerTest()
{
    printf("pointerTest start\n");
    //int * array = new int[]{1,2,3,4};
    int array[] = {1, 2, 3, 4};
    int* pArray = array;
    int value = *(int *)(pArray = pArray + 2, pArray - 2);//如果结合宏扩展，运用逗号表达式（逗号表达式取最后一个值作为结果值返回），可以实现先获取pArray内存值，然后移动指针
    printf("pointerTest value=%d the value of pArray=%d\n", value,*pArray);
    printf("pointerTest end\n");
}







