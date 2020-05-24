#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "string"
#include "vector"
#include "set"
#include "queue"
#include "map"
#include "deque"
#include "iostream"
#include "assert.h"
#include "bitset"
#include "algorithm"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define pb push_back
#define mem(a, b) memset(a, b, sizeof(a))
#define SZ(a) (int)a.size()
#define clr(a) a.clear()
#define MP(a, b) make_pair(a, b)

#define MAX 1000+10



int par[MAX];
int rnk[MAX];
int cnt[MAX];
int isCon[MAX];

void make_set(int n)
{
    for(int i = 0 ; i<=n ; i++)
    {
        rnk[i] = 0;
        par[i] = i;
        cnt[i] = 0;
        isCon[i] = 0;
    }
    return;
}

int find_par(int x)
{
    if(x!=par[x] ) return par[x] = find_par(par[x]);
    else return x;
}

void u_nion(int x,int y)
{
    if(rnk[x]>rnk[y])
    {
        par[y] = x;
    }
    else par[x] = y;
    if(rnk[x]==rnk[y]) rnk[y]++;
    return ;
}

void link(int x,int y)
{
    u_nion(find_par(x) , find_par(y));
}

vector<pair< int, pair<int,int> > >v;
int total;


int mst(int n)
{
    int total_cost = 0;
    for(int i = 0 ; i<SZ(v) && total  < n; i++)
    {
        int uu = v[i].second.first;
        int vv = v[i].second.second;

        int cc = v[i].first;

        if(find_par(uu)!=find_par(vv))
        {
            if(isCon[find_par(uu)] && isCon[find_par(vv)]) continue;
            if(isCon[find_par(uu)] || isCon[find_par(vv)])
            {
                if(isCon[find_par(uu)]) total += cnt[find_par(vv)];
                else total += cnt[find_par(uu)];

                int tmp = cnt[find_par(uu)] + cnt[find_par(vv)];
                link(uu,vv);

                isCon[find_par(uu)] = isCon[find_par(vv)] = 1;
                cnt[find_par(uu)] = cnt[find_par(vv)] = tmp;
            }
            else
            {
                int tmp = cnt[find_par(uu)] + cnt[find_par(vv)];
                link(uu,vv);
                cnt[find_par(uu)] = cnt[find_par(vv)] = tmp;
            }
            total_cost += cc;
        }
    }
    return total_cost;
}

int main()
{
    #ifdef PGD_LAB
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif

    int n,m , k;

    int tcase,cas=1;

    scanf(" %d",&tcase);

    while(tcase--)
    {
        total = 0;
        scanf(" %d %d %d",&n,&m,&k);

        make_set(n);
        v.clear();

        for(int i= 1 ; i<=k ; i++)
        {
            int p;
            scanf(" %d",&p);
            cnt[p] = 1;
            isCon[p] = 1;
            total++;
        }
        for(int i = 1 ; i<=m ; i++)
        {
            int uu,vv,cc;
            scanf(" %d %d %d" , &uu,&vv,&cc);
            v.push_back( make_pair(cc , MP(uu,vv)));
        }

        sort(v.begin() , v.end());

        int val= mst(n);

        printf("Case #%d: %d\n",cas++ , val);
    }


    return 0;
}






