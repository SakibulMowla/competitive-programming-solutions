#include "stdio.h"

int x[] = {2,2,-2,-2,1,1,-1,-1};
int y[] = {1,-1,1,-1,2,-2,2,-2};

int main()
{
    int t,n,m,k,i;
    char arr[3];
    scanf("%d",&t);
    while(t--)
    {
        k = 0;
        scanf("%s",arr);
        n = arr[0] - 'a' + 1;
        m = arr[1] - '0';
        for(i=0;i<8;i++)
        {
            if(n+x[i] >=1 && n+x[i] <=8 && m+y[i] >= 1 && m+y[i] <= 8)
                k++;
        }
        printf("%d\n",k);
    }

    return 0;
}
