#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;
#define SZ 55

struct data
{
    int w,h;
};

data arr[SZ];
int dp[SZ][3] , H , W ,n;

bool comp(data p,data q)
{
    return p.w < q.w;
}

int solve()
{

}

int main()
{
    int i,j,k,t=0,test;
    scanf("%d",&test);
    while(test--)
    {
        k = 0;
        scanf("%d %d %d",&n,&H,&W);
        for(i=0; i<n; i++)
        {
            scanf("%d %d",&arr[i].w,&arr[i].h);
            if(arr[i].h > k) k = arr[i].h;
        }
        sort(arr,arr+n,comp);

    }

    return 0;
}
