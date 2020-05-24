#include "stdio.h"
#include "string.h"
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

#define SZ 100

struct data
{
    int pos,num;
};

bool comp(data p,data q)
{
    return p.num > q.num;
}

int teams,tables;
int seat[SZ];
vector <data> member;
vector <int> ans[SZ];

int solve()
{
    sort(member.begin(),member.end(),comp);
    int i,j,k,n,m;
    for(i=0; i<teams; i++)
    {
        k = member[i].num;
        for(j=1; j<=tables; j++)
        {
            if(!k) break;
            if(seat[j])
            {
                k--;
                ans[member[i].pos].push_back(j);
                seat[j]--;
            }
        }
        if(k) return 0;
    }
    return 1;
}

int main()
{
    int i,j;
    data u;
    while(scanf("%d %d",&teams,&tables) == 2 && (teams + tables))
    {
        member.clear();
        for(i=1; i<=teams; i++)
        {
            u.pos = i;
            scanf("%d",&u.num);
            member.push_back(u);
            ans[i].clear();
        }
        for(i=1; i<=tables; i++) scanf("%d",&seat[i]);
        printf("%d\n",i=solve());
        if(i)
        {
            for(i=1; i<=teams; i++)
            {
                for(j=0; j<ans[i].size(); j++)
                {
                    if(j) printf(" ");
                    printf("%d",ans[i][j]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}
