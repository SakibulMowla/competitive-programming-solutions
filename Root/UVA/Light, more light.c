#include<stdio.h>
#include<math.h>

int main(void)
{
    double n,m;
    while(scanf("%lf",&n)==1)
    {
        if(n==0)
            break;
        m=sqrt(n);
        if(m==(int)m)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}

