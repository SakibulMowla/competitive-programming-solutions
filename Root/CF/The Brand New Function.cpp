#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace  std;

#define SZ 100010

int arr[SZ];
map <int , int > M;

int main()
{
    int i,j,k,n,cnt;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    cnt = 0;
    for(i=0;i<n;i++)
    {
        k = arr[i] ;
        for(j=i+1;j<n;j++)
        {
            k = k | arr[j];
            printf("k = %d\n",k);
        }
        if(M.find(k) == M.end())
            M[k] = 1 , cnt++;
    }
    printf("%d\n",cnt);

    return 0;
}
