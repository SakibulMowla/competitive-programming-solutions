const int mod = 100001;
#define SZ 100000010

#include "stdio.h"
int arr[SZ] , coin[] = {1,2,3};

int main()
{
    int i,j,t,n;
    arr[0] = 1;
    for(i=0;i<3;i++)
        for(j=coin[i];j<SZ;j++)
            arr[j] = (arr[j] + arr[j-coin[i]]) % mod;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",arr[n]);
    }

    return 0;
}
