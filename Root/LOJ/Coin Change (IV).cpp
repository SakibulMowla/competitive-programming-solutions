#include "stdio.h"
#include "stdlib.h"
#include "algorithm"
#define SZ 19685

int arr1[SZ], arr2[SZ], num1, num2;
int arr[20];

bool b_search(int item)
{
    int lo, hi, mid;
    lo = 0;
    hi = num1 - 1;

    while(lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if(arr1[mid] == item) return 1;
        if(arr1[mid] > item) hi = mid-1;
        else lo = mid+1;
    }
    return 0;
}

void all_possible_left(int b,int e,int val)
{
    if(b == e)
    {
        arr1[num1++] = val;
        return;
    }
    int i;
    for(i=0; i<3; i++)
        all_possible_left(b+1, e, val + arr[b]*i);
}

void all_possible_right(int b,int e,int val)
{
    if(b == e)
    {
        arr2[num2++] = val;
        return;
    }
    int i;
    for(i=0; i<3; i++)
        all_possible_right(b+1, e, val + arr[b]*i);
}

int main()
{
    int t=0, test, n, k, i, sum, f;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%d %d",&n,&k);
        for(i=0; i<n; i++)    scanf("%d",&arr[i]);

        num1 = num2 = 0;

        all_possible_left(0, n/2, 0);
        all_possible_right(n/2, n, 0);

        std::stable_sort(arr1,arr1+num1);

        f = 0;

        for(i=0; i<num2; i++)
            if(k >= arr2[i] && b_search(k-arr2[i]))
            {
                f = 1;
                break;
            }

        printf("Case %d: ",++t);
        if(f) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
