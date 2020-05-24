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

int arr[1100];

bool inside(int a, int b, int c)
{
    if(a > b) swap(a, b);
    if(c > a && c < b)
        return true;
    return false;
}

bool outside(int a, int b, int c)
{
    if(a > b) swap(a, b);
    if(c < a || c > b)
        return true;
    return false;
}

int main()
{

    int n, m, i, j, k, flag;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    flag = 1;

    for(i=1;i<n;i++)
    {
        for(k=0;k<n-2;k++)
        {
            if( ( inside(arr[i],arr[i-1],arr[k]) && outside(arr[i], arr[i-1], arr[k+1]) ) ||  (inside(arr[i],arr[i-1],arr[k+1]) && outside(arr[i], arr[i-1], arr[k])) )
            {
                flag = 0;
                break;
            }
        }
    }

    if(flag)
        printf("no\n");
    else
        printf("yes\n");


    return 0;
}

