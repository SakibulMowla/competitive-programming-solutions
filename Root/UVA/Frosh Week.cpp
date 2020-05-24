#include <stdio.h>

#define SZ 1000010

long arr[SZ] , temp[SZ] , count;

void merging(long left,long mid,long right)
{
    long i=left , j = mid+1 , k = 0;
    long len_left = mid-left+1;
    while(i<=mid && j<=right)
    {
        if(arr[i] > arr[j])
        {
            count += len_left-(i-left);
            temp[k++] = arr[j++];
        }
        else temp[k++] = arr[i++];
    }
    while(i <= mid)temp[k++] = arr[i++];
    while(j <= right)temp[k++] = arr[j++];
    for(i=0;i<k;i++)
        arr[left+i] = temp[i];
    return;
}

void mergeSort(long left,long right)
{
    long mid = (left + right) / 2;
    if(left < right)
    {
        mergeSort(left , mid);
        mergeSort(mid+1 , right);
        merging(left , mid , right);
    }
    return;
}

int main()
{
    long n,i;
    while(scanf("%ld",&n) == 1)
    {
        for(i=0;i<n;i++)
            scanf("%ld",&arr[i]);
        count = 0;
        mergeSort(0 , n-1);
        printf("%ld\n",count);
    }

    return 0;
}
