#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>

using namespace  std;

typedef long long ll;

#define SZ 3000

int arr[SZ];

int main()
{
    int t, n, i, j, k;

    char srr[100];

    scanf("%d",&t);

    while(t--)
    {
        scanf("%s",srr);
        scanf("%d",&n);

//        printf("yes\n");

        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);

//            printf("yes\n");

        sort(arr, arr+n);

        if(srr[0] == 'F')
            printf("%d\n",arr[0]);
        else
            printf("%d\n",arr[n-1]);
    }

    return 0;
}









