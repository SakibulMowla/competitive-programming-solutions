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

typedef long long ll;
/*ll bigmod(ll a,ll b,ll m)
{
    if(b == 0) return 1%m;
    ll x = bigmod(a,b/2,m);
    x = (x * x) % m;
    if(b % 2 == 1) x = (x * a) % m;
    return x;
}*/

ll x[] = {0,0,-1,1};//4-way
ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

template <class T> T GCD(T a,T b)
{
    if(b == 0) return a;
    return GCD(b,a%b);
}

template <class T> T LCM(T a,T b)
{
    return (a*b) / GCD(a,b);
}

typedef pair<ll,ll> pii;
const ll inf = 1<<28;
#define MP(a,b) make_pair(a,b)
#define SZ 510
ll r,c,cnt,now;
char arr[SZ][SZ];
ll col[SZ][SZ];
//map <pii , ll> pr;

ll dfs(ll p,ll q)
{
    if(arr[p][q] == 'C')
        cnt++;
    col[p][q] = now;
    ll i,u,v;
    for(i=0; i<4; i++)
    {
        u = p + x[i];
        v = q + y[i];
        if(u >= 0 && v >= 0 && u < r && v < c && col[u][v] != now && arr[u][v] != '#')
            dfs(u,v);
    }
}

ll res[1010];

//%I64d
int main()
{
    ll  q,i,j,k,test,t=0;
    cin >> test;
    while(test--)
    {
        cin >> r >> c >> q;
        for(i=0; i<r; i++)
            scanf("%s",arr[i]);
        now = 0;
//        pr.clear();
        memset(res,0,sizeof(res));
        memset(col,0,sizeof(col));
        printf("Case %lld:\n",++t);
        while(q--)
        {
            cin >> i >> j;
            --i;--j;
            if( col[i][j] )
            {
                printf("%lld\n",res[col[i][j]]);
                continue;
            }
            else
            {
                cnt = 0;
                now++;
                dfs(i,j);
                res[now] = cnt;
                printf("%lld\n",cnt);
            }
//            pr[MP(i,j)] = cnt;
        }
    }

    return 0;
}
