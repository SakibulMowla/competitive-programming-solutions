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

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

//template <class T> T gcd(T a, T b)
//{
//    while(b) b ^= a ^= b ^= a %= b;
//    return a;
//}
//
//template <class T> T lcm(T a, T b)
//{
//    return (a/gcd(a,b)) * b;
//}

typedef pair<ll,ll> pii;
const ll inf = 1<<28;
#define MP(a,b) make_pair(a,b)
#define SZ 510

ll n , matr[SZ][SZ] , mark[SZ];
ll dist[SZ];


struct data
{
    ll city,dist;
    bool operator < (const data& p) const {
        return dist > p.dist;
    }
};

ll dij(ll s,ll t)
{
    ll i,j,k,u;
    for(i=1; i<=n; i++)
        dist[i] = inf;
    priority_queue <data> Q;
    data var , po;
    var.city = s;
    var.dist = 0ll;
    Q.push(var);
    dist[s] == 0ll;
    while(!Q.empty())
    {
        var = Q.top();
        j = var.city;
        u = var.dist;
        Q.pop();
        u = dist[var.city];
        for(i=1;i<=n;i++)
        {
            if(mark[i] == 0 && matr[var.city][i] != 0)
            {
                po.city = i;
                po.dist = matr[var.city][i] + var.dist;
                if(dist[i] > po.dist)
                {
                    dist[i] = po.dist;
                    Q.push(po);
                }
            }
        }
    }
    return dist[t];
}

//%I64d
int main()
{
    ll i,j,k,sum,p,q;
    while(cin >> n)
    {
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
            {
                cin >> matr[i][j];
            }
        memset(mark,0ll,sizeof(mark));
        sum = 0ll;
        for(k=1; k<=n; k++)
        {
            sum = 0ll;
            for(i=1; i<=n; i++)
            {
                if(mark[i] == 0)
                    for(j=i+1; j<=n; j++)
                    {
                        if(mark[j] == 0)
                        {
                            q = dij(i,j);
                            if(q < inf)
                                sum += q;
                            q = dij(j,i);
                            if(q < inf)
                                sum += q;

                        }
                    }
            }
            cout << sum << " ";
            cin >> p;
            mark[p] = 1ll;
        }
        printf("\n");
    }

    return 0;
}
