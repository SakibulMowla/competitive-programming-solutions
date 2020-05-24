#include <stdio.h>
#include <math.h>

#define SZ 1000000000

short arr[SZ];

int main()
{
    int i,k,n,m,sum;
    while(scanf("%d %d",&n,&m) == 2 && (n || m))
    {
        sum = 0;
        for(i=n;i<=m;i++)
        {
            k = i;
            while(k)
            {
                sum += k % 10;
                k /= 10;
            }
        }
        printf("%d\n",sum);
    }

    return 0;
}
