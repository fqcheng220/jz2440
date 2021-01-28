
#include<stdio.h>


int main()
{
    unsigned int 	*p	= (unsigned int *)

                          malloc(sizeof(unsigned int));
    *p					= 0xfffffffe;
    unsigned int	i1	= 0;

    if (i1 == 0)
    {
        printf("yes it's %d\n", i1);
    }

    unsigned int	i2	= 1;

    if (i2 == 1)
    {
        printf("yes it's %d\n", i2);
    }

    unsigned int	tmp = *p;
    unsigned int	tmp2 = 1 << 0;

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
    printf("before %d \n",iTest);
    iTest &= ~(1<<4);
    printf("after %d \n",iTest);
}







