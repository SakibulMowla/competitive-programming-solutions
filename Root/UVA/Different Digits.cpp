#include <stdio.h>
#include <string.h>

int pre[5010];

int main()
{
    int i,j,k,test[10];
    for(i=1;i<=5000;i++)
    {
        k = i;
        memset(test,0,sizeof(test));
        while(k)
        {
            j = k % 10;
            test[j]++;
            if(test[j] > 1) break;
            k /= 10;
        }
        if(k != 0) pre[i] = pre[i-1];
        else pre[i] = pre[i-1] + 1;
    }

    while(scanf("%d %d",&i,&j) == 2)
    {
        k = pre[j] - pre[i-1];
        printf("%d\n",k);
    }

    return 0;
}
