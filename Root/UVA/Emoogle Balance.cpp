#include <stdio.h>

int main()
{
    int n,i,a,b,num,test;
    test = 0;
    while(scanf("%d",&n) == 1 && n)
    {
        a = b = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&num);
            if(!num)b++;
            else a++;
        }
        printf("Case %d: %d\n",++test,a-b);
    }

    return 0;
}
