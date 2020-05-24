#include "stdio.h"
#include "vector"
#include "iostream"
#define SZ 110
using namespace std;

vector <int> edge[SZ];
int dp[SZ][210] , e;
bool found;

int solve(int city,int day)
{
//    printf("city = %d day = %d\n",city,day);
    if(found) return 1;
    if(day == 0)
    {
        if(city == e) return 1;
        return 0;
    }
//    printf("city = %d day = %d\n",city,day);
    if(dp[city][day] != -1) return dp[city][day];
//    printf("city = %d day = %d\n",city,day);
    int i,j,ans=0;
    for(i=0;i<edge[city].size();i++)
    {
        j = edge[city][i];
        ans = max(ans,solve(j,day-1));
    }
    if(ans == 1) found = true;
    return dp[city][day] = ans;
}

int main()
{
    int i,j,k,c,l,s,d;
    while(scanf("%d %d",&c,&l) == 2 &&(c+l))
    {
        for(i=0; i<=c; i++) edge[i].clear();
        for(i=0; i<l; i++)
        {
            scanf("%d %d",&j,&k);
            edge[j].push_back(k);
            edge[k].push_back(j);
        }
        scanf("%d %d %d",&s,&e,&d);
        for(i=0;i<=c;i++) for(j=0;j<=d;j++) dp[i][j] = -1;
        found = false;
        if(solve(s,d)) printf("Yes, Teobaldo can travel.\n");
        else printf("No, Teobaldo can not travel.\n");
    }

    return 0;
}
