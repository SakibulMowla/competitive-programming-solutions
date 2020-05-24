#include <stdio.h>

int main()
{
    int n,t,test,dust,sum;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        sum = 0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&dust);
            if(dust > 0)
                sum += dust;
        }
        printf("Case %d: %d\n",++t,sum);
    }

    return 0;
}
