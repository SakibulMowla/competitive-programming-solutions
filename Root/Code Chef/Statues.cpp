#include "bits/stdc++.h"
using namespace std;

int arr[55];

int main()
{
    int n, m, i, j, k, test=0;

    while(scanf("%d",&n) == 1 && n)
    {
        k = 0;
        for(i=0; i<n; i++)
        {
            scanf("%d",arr+i);
            k += arr[i];
        }
        j = k / n;
//        printf("j = %d\n",j);
        k = 0;
        for(i=0; i<n; i++)
        {
            k += (arr[i] < j) ? (j - arr[i]) : 0;
//            printf("k = %d\n",k);
        }
        printf("Set #%d\n",++test);
        printf("The minimum number of moves is %d.\n\n",k);
    }

    return 0;
}
