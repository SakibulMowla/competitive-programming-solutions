#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace  std;

#define inf 1<<28
#define SZ 1000

int N , arr[SZ][SZ] , col[1000050];

map <int ,int > M;

void sieve()
{
//    printf(" n = %d\n",N);
    int i,j,k;
    for(i=4;i<N;i+=2)  col[i] = 1;
    col[0] = col[1] = 1;
    for(i=3;i<sqrt(N);i+=2)
        if(col[i] == 0)
            for(j=i*i;j<N;j+=i+i)
                col[j] = 1;
    for(i=0;i<N;i++)
    {
        if(col[i] == 0)
        {
//            printf("i = %d\n",i);
            M[i] = i;
            for(j=i-1;col[j]!=0;j--)
                M[j] = i;
        }
    }
}

int main()
{
    int  i,j,k,n,m,ans;

    while(scanf("%d %d",&n,&m) == 2)
    {
        N = 0;
        for(i=0;i<n;i++) for(j=0;j<m;j++) {scanf("%d",&arr[i][j]) ; if(arr[i][j] > N) N =arr[i][j];}
        N = N*10 +10;
        M.clear();
//        printf("yes\n");
        sieve();
        ans = 1<<28;
//        printf("yes\n");
        for(i=0;i<n;i++)
        {
            k = 0;
            for(j=0;j<m;j++)
            {
                k += M[ arr[i][j] ] - arr[i][j];
            }
            ans = min(ans,k);
        }
//        printf("yes\n");
        for(j=0;j<m;j++)
        {
            k = 0;
            for(i=0;i<n;i++)
            {
                k += M[ arr[i][j] ] - arr[i][j];
            }
            ans = min(k,ans);
        }
//        printf("yes\n");
        printf("%d\n",ans);
    }

    return 0;
}
