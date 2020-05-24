#include <stdio.h>
#include <math.h>

int main()
{
    int n,m,c;
    while(scanf("%d %d",&n,&m)==2)
    {
        if(n==-1 && m==-1)
            break;
        c=abs(n-m);
        if(c>50)
            c=(100-c);
        printf("%d\n",c);
    }

    return 0;
}
