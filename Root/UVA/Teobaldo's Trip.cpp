#include "stdio.h"
#include "vector"
#include "iostream"

using namespace std;

#define SZ 110
#define SZ1 210

bool found;
vector <int> edge[110];
int dp[SZ][SZ1],e;

int solve(int city,int day)
{
    if(found) return 1;
    if(day == 0)
    {
        if(city == e) return 1;
        return 0;
    }
    if(dp[city][day] != -1) return dp[city][day];
    int i,j,ans=0;
    for(i=0;i<edge[city].size();i++)
    {
        j = edge[city][i];
        ans = max(ans , solve(j,day-1));
    }
    if(ans) found = true;
    return dp[city][day] = ans;
}

int main()
{
    int c,l,i,j,k,d;
    while(scanf("%d %d",&c,&l) == 2 &&(c+l))
    {
        for(i=0;i<=c;i++) edge[i].clear();
        for(i=0;i<l;i++)
        {
            scanf("%d %d",&j,&k);
            edge[j].push_back(k);
            edge[k].push_back(j);
        }
        scanf("%d %d %d",&k,&e,&d);
        for(i=0;i<=c;i++) for(j=0;j<=d;j++) dp[i][j] = -1;
        found = false;
        if(solve(k,d)) printf("Yes, Teobaldo can travel.\n");
        else printf("No, Teobaldo can not travel.\n");
    }

    return 0;
}
