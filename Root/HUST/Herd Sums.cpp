#include <stdio.h>

int main()
{
    int n,cnt,sum,i,j;
    while(scanf("%d",&n) == 1)
    {
        cnt = 0;
        for(i=1; i<= n/2 + 1; i++)
        {
            sum = 0;
            for(j=i; j<= n/2 + 1; j++)
            {
                sum += j;
                if(sum == n) cnt++;
                if(sum > n ) break;
            }
        }
        printf("%d\n",cnt+1);
    }

    return 0;
}
