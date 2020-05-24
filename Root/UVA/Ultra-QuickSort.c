// 10810 - Ultra QuickSort

#include <stdio.h>

#define SZ 1000010
#define inf 1000000000

long arr[SZ] , L[SZ] , R[SZ] , count;

void merging(long left,long mid,long right)
{
    long i,j,k,len1 = 0,len2 = 0;
    for(i=left; i<=mid; i++)
        L[len1++] = arr[i];
    L[len1] = inf;
    for(j=mid+1; j<=right; j++)
        R[len2++] = arr[j];
    R[len2] = inf;
    i = j = 0;
    for(k=left; k<=right; k++)
    {
        if(L[i] > R[j])
        {
            count += len1-i;
            arr[k] = R[j];
            j++;
        }
        else
        {
            arr[k] = L[i];
            i++;
        }
    }
}

void merge(long left,long right)
{
    long mid = (left + right) / 2;
    if(left < right)
    {
        merge(left,mid);
        merge(mid+1,right);
        merging(left,mid,right);
    }
    return;
}

int main()
{
    long n,i;
    while(scanf("%ld",&n) == 1)
    {
        for(i=0; i<n; i++)
            scanf("%ld",&arr[i]);
        count = 0;
        merge(0,n-1);
        printf("%ld\n",count);
    }
    return 0;
}
