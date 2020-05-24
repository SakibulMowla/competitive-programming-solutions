#include "stdio.h"
#include "algorithm"
#include "iostream"
using namespace std;

#define SZ 110

int arr[SZ];

int main()
{
    int t,n,m,i,j,k,sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        sum = 0;
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]) , sum += arr[i];
        j = 0;
        sort(arr,arr+n);
        for(i=0;i<m;i++)
            j += arr[i];
        k = abs(j-(sum - j));
        j = 0;
        for(i=n-1;i>=n-m;i--)
            j += arr[i];
        k = max(k,abs(j-(sum-j)));
        printf("%d\n",k);
    }

    return 0;
}
