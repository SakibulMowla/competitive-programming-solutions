#include "stdio.h"
#include "iostream"
#define SZ 65
using namespace std;
typedef long long ll;
const ll inf = 1<<28;
ll n,m,r;
ll ans[SZ][SZ][SZ] , circuit[SZ][SZ][SZ];

void take_input()
{
    ll i,j,k;
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            for(k=1; k<=n; k++)
            {
                cin >> circuit[i][j][k];
//                ans[i][j][k] = inf;
//                if(circuit[i][j][k] == 0) circuit[i][j][k] = inf;
//                matrix[i][j][k] = inf;
            }
    for(i=0; i<=n; i++)
        for(j=1; j<=n; j++)
            for(k=1; k<=n; k++)
                ans[i][j][k] = inf;
}

void floyd(ll tmp[SZ][SZ])
{
    ll i,j,k;
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
            {
                tmp[i][j] = min(tmp[i][j] , tmp[i][k] + tmp[k][j]);
                ans[0][i][j] = min(ans[0][i][j] , tmp[i][j]);
            }
}

ll solve()
{
    ll x,y,z,k;
    /*for(x = 1; x<=m; x++)
        for(y=1; y<=n; y++)
            for(z=1; z<=n; z++)
            {
                ans[0][y][z] = min(ans[0][y][z] , circuit[x][y][z]);
            }*/

    for(x=1; x<=n; x++)
        for(y=1; y<=n; y++)
            for(z=1; z<=n; z++)
                for(k=1; k<=n; k++)
                {
                    ans[x][y][z] = min(ans[x][y][z] , ans[x-1][y][k] + ans[0][k][z]);
                }
}

//%I64d
int main()
{
    ll i,s,t,k;
    while(cin >> n >> m >> r)
    {
        take_input();
        for(i=1; i<=m; i++) floyd(circuit[i]);
        solve();
        while(r--)
        {
            cin >> s >> t >> k;
            k = min(k,n);
            printf("%I64d\n",ans[k][s][t]);
        }
    }

    return 0;
}
