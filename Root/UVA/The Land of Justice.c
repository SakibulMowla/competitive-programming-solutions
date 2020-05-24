#include <stdio.h>

int main()
{
    long long int n,m;
    char c='%';
    while(scanf("%lld",&n)==1)
    {
        if(n<0)
            break;
        if(n==1)
            printf("0%c\n",c);
        else
        {
            m=n*25;
            printf("%lld%c\n",m,c);
        }
    }
    return 0;
}
