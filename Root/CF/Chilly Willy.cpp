#include "stdio.h"
#include "string.h"

const int mod = 2*3*5*7;

int main()
{
    int i,j,n;
    while(scanf("%d",&n) == 1)
    {
        if(n<=2) printf("-1\n");
        else if(n == 3) printf("210\n");
        else
        {
            j = 1;
            for(i=0;i<n-1;i++) j = (j * 10) % mod;
            printf("1");
            for(i=0;i<n-4;i++) printf("0");
            printf("%03d\n",210-j);
        }
    }

    return 0;
}
