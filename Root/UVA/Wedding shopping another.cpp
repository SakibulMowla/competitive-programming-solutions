#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

#define inf -1<<28

vector <int> wed[21];
int dp[201][21];

int shop(int m,int c)
{
    if(dp[m][c] != -1) return dp[m][c];
    if(m<0) return inf;
    if(c==0) return 0;
    int i,tmp,ans;
    ans = inf;
    for(i=0;i<wed[c].size();i++)
    {
        tmp = wed[c][i];
        if(shop(m-tmp,c-1) != inf)
            if(shop(m-tmp,c-1) + tmp > ans && shop(m-tmp,c-1) + tmp <= m)
                ans = shop(m-tmp,c-1) + tmp;
    }

    return dp[m][c] = ans;
}

int main()
{
//    freopen("1.txt","r",stdin);
    int n,m,c,k,i,j,num,ans;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&m,&c);
        for(i=0;i<=m;i++) for(j=0;j<=c;j++) dp[i][j] = -1;
        for(i=1;i<=c;i++) wed[i].clear();
        for(i=1;i<=c;i++)
        {
            scanf("%d",&k);
            for(j=0;j<k;j++) scanf("%d",&num) , wed[i].push_back(num);
        }
        ans = shop(m,c);
        if(ans != inf) printf("%d\n",ans);
        else printf("no solution\n");
    }

    return 0;
}
