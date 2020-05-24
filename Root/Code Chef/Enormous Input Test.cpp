#include <stdio.h>

int main()
{
    int n,num,k,cnt;
    while(scanf("%d %d",&n,&k) == 2)
    {
        cnt = 0;
        while(n--)
        {
            scanf("%d",&num);
            if(num%k == 0) cnt++;
        }
        printf("%d\n",cnt);
    }

    return 0;
}
