#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>

//#include <bits/stdc++.h>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())

typedef long long ll;
typedef pair<ll,ll> pii;

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){while(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

#define SZ 100010
const ll inf = 1LL<<28;
const ll mod = 1LL;

struct data
{
    int x, y, z;
};

data arr[SZ];

bool comp(data p,data q)
{
    return p.z > q.z;
}

int par[SZ];
int mark[SZ];

int find(int r)
{
    if(r == par[r])
        return r;
    return r = find(par[r]);
}


int MST(int n, int m)
{
    int i, x, y, cnt = 0;

    for(i=0; i<m; i++)
    {
        x = find(arr[i].x);
        y = find(arr[i].y);

        if(x == y) continue;

//        printf("conm  %d %d %d\n",arr[i].x,arr[i].y,arr[i].z);

        cnt++;
        par[x] = y;
        mark[i] = 1;
    }

    return cnt;
}


//%I64d
int main()
{
//    freopen("1.txt","r",stdin);

    int t, n, m, i, j, k, c, koyta, employ, old, cost, need;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d %d",&n,&m,&c);

        for(i=0; i<=n; i++)
        {
            par[i] = i;
        }

        for(i=0;i<=m;i++)
        {
            mark[i] = 0;
        }

        for(i=0; i<m; i++)
        {
            scanf("%d %d %d",&arr[i].x,&arr[i].y,&arr[i].z);
        }

        sort(arr, arr+m, comp);

        employ = old = cost = 0;

        koyta = MST(n, m);

        need = n-1-koyta;

//        printf("koyta = %d\n",koyta);

        for(i=m-1;i>=0;i--)
        {
            if(need == 0) break;
            if(mark[i] == 1) continue;
            if(arr[i].z > c) break;

//            printf("i = %d\n",i);

            old++;
            cost += arr[i].z;
            need--;
        }

        employ = need;
        cost += (need*c);

        printf("%d %d %d\n",employ,old,cost);
    }



    return 0;
}


/*

7 6 5

1 2 1  2 3 2  3 4 3  4 5 4  5 1 6  1 4 5

*/
