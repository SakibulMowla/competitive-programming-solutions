#include "stdio.h"

int main()
{
    int t=0,test,n,i,res,num;
    long long sum;
    scanf("%d",&test);
    while(test--)
    {
        res = sum = 0;
        scanf("%d",&n);
        num = n;
        while(n--)
        {
            scanf("%d",&i);
            res ^= i;
            sum += i;
        }
        if((sum == num && res == 1) || (sum != num && res == 0)) printf("Case %d: Bob\n",++t);
        else printf("Case %d: Alice\n",++t);
    }

    return 0;
}
