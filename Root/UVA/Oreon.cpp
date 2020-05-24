#include "stdio.h"
#include "string.h"
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

#define SZ 300
#define makeset(n) for(i=0;i<=n;i++) par[i] = i

struct data{ int a,b,c; };
bool comp(data p,data q){ return p.c < q.c; }

int par[SZ],visit[SZ][SZ];
vector <data> v;

int find(int r)
{
    return par[r] == r ? r : par[r] = find(par[r]);
}

char conv_char(int i)
{
    if(i>=26)
        return (i-26+'a');
    return (i+'A');
}

void MST(int n)
{
    sort(v.begin(),v.end(),comp);
    int p,q,i;
    for(i=0;i<v.size();i++)
    {
        p = find(v[i].a);
        q = find(v[i].b);
        if(p == q)continue;
        par[p] = q;
        printf("%c-%c %d\n",conv_char(v[i].a),conv_char(v[i].b),v[i].c);
    }
}

int main()
{
    data u;
    int test,Case,i,j,n,cost;
    char z;
//    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    Case = 0;
    while(test--)
    {
        scanf("%d",&n);
        v.clear();
        makeset(n);
        for(i=0;i<n;i++)for(j=0;j<n;j++)visit[i][j] = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(j==n-1)
                    scanf("%d",&cost);
                else
                    scanf("%d %c",&cost,&z);
                if(cost == 0)continue;
                if( !visit[i][j] )
                {
                    visit[i][j] = visit[j][i] = 1;
                    u.a = i;
                    u.b = j;
                    u.c = cost;
                    v.push_back(u);
                }
            }
        }
        printf("Case %d:\n",++Case);
        MST(n);
    }

    return 0;
}
