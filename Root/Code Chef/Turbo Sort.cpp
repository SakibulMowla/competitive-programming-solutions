#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define SZ 1000010
int arr[SZ];
int main()
{
    int i , n ;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    sort(arr,arr+n);
    for(i=0;i<n;i++) printf("%d\n",arr[i]);

    return 0;
}
