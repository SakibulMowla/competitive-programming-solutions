using namespace std;

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "vector"
#include "iostream"

#define SZ 110
#define sz(a) (int)a.size()

typedef long long ll;

struct data
{
    int x, y;
};

struct data1
{
    int x, y, s;
};

data rest[25];
data1 soli[SZ];
bool col[SZ];
vector <int> adj[25];

int main()
{
    int i, j, k, l, d, m, r, lim, sum, best, p;

    scanf("%d %d",&k,&r);

    r = r * r;

    scanf("%d",&m);
    for(i=0; i<m; i++)
        scanf("%d %d",&rest[i].x, &rest[i].y );

    scanf("%d",&l);
    for(i=0; i<l; i++)
        scanf("%d %d %d",&soli[i].x, &soli[i].y, &soli[i].s);

    for(i=0; i<m; i++) adj[i].clear();

    for(i=0; i<m; i++) for(j=0; j<l; j++)
        if((rest[i].x-soli[j].x)*(rest[i].x-soli[j].x) + (rest[i].y - soli[j].y)*(rest[i].y - soli[j].y) <= r)
            adj[i].push_back(j);

    lim = 1<<m;
    best = 0;

    while(lim--)
    {
        if(__builtin_popcount(lim) != k) continue;

        sum = 0;
        memset(col, 0, sizeof(bool)*(l+2));

        for(i=0; i<m; i++) if(lim & (1LL<<i))
            {
                p = sz(adj[i]);
                for(j=0; j<p; j++)
                    col[ adj[i][j] ] = 1;
            }

        for(i=0; i<l; i++)
            if(col[i] == 1)
                sum += soli[i].s;

        if(sum > best) best = sum;
    }

    printf("%d\n",best);

    return 0;
}
