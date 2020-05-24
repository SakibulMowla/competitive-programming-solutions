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
    int b, e;
};

data arr[SZ];

struct res
{
    int oppo, m , a;
    res()
    {
        m = 0;
    }
};

res first[SZ], last[SZ];

bool comp(data p,data q)
{
    return p.e < q.e;
}

int end[SZ], beg[SZ], ball[SZ], ans[SZ];

map <int, int> m1, m2;

int cnt(int b,int e,int n)
{
    int i, j, k, p, q;
    k = end[e] - end[b-1];
    if(1 || (m2[e] - m1[b] <= m2[n] - m1[e+1]) || e+1>n )
    {
        p = m1[b];
        q = m2[e];
        j = 0;
        for(i=p;i<=q;i++)
            if(arr[i].b < b)
                j++;
//        printf("j = %d\n",j);
        return (k - j);
    }
    else
    {
//printf("yes\n");
        p = m1[e+1];
        q = m2[n];
        j = 0;
        for(i=p;i<=q;i++)
            if(arr[i].b < b)
                j++;
//        printf("k = %d beg[b-1] = %d end[b-1] = %d j = %d\n",k,beg[b-1],end[b-1],j);
        return (k - (beg[b-1] - end[b-1] - j));
    }
}

//%I64d
int main()
{
    int n, m, i, j, k, x, y;

    scanf("%d %d",&n,&m);

    for(i=1;i<=n;i++)
        scanf("%d",&ball[i]);

    for(i=0;i<m;i++)
    {
        scanf("%d %d",&arr[i].b,&arr[i].e);
        beg[arr[i].b]++;
        end[arr[i].e]++;
    }

    for(i=1;i<=n;i++)
        beg[i] += beg[i-1], end[i] += end[i-1];

    sort(arr, arr+m, comp);

    for(i=0;i<m;i++)
    {
        m2[arr[i].e] = i;
    }

    for(i=m-1;i>=0;i--)
    {
        m1[arr[i].e] = i;
    }

    m1[n+1] = n+1;

    for(i=n;i>=1;i--)
    {
        if(m1.find(i) == m1.end())
            m1[i] = m1[i+1];
    }

    m1[n+1] = 0;

    m2[0] = 0;

    for(i=1;i<=n;i++)
    {
        if(m2.find(i) == m2.end())
            m2[i] = m2[i-1];
    }

//printf("end[2] = %d\n",end[2]);

    scanf("%d",&k);

    ans[0] = 0;

    for(i=1;i<=k;i++)
    {
        scanf("%d",&x);
        y = x + ans[i-1];
        ans[i] = ans[i-1];
        if(y >= 1 && y <= n && ball[y] == 1)
        {
            if(first[y+1].m && last[y-1].m)
            {
                j = cnt(last[y-1].oppo, first[y+1].oppo, n);
                ans[i] = ans[i] + j - first[y+1].a - last[y-1].a;
                first[ last[y-1].oppo ].a = j;
                first[ last[y-1].oppo ].m = 1;
                first[ last[y-1].oppo ].oppo = first[y+1].oppo;
                last[ first[y+1].oppo ].a = j;
                last[ first[y+1].oppo ].m = 1;
                last[ first[y+1].oppo ].oppo = last[y-1].oppo;
            }
            else if(first[y+1].m)
            {
                j = cnt(y, first[y+1].oppo, n);
                ans[i] = ans[i] + j - first[y+1].a;
                first[y].a = j;
                first[y].m = 1;
                first[y].oppo = first[y+1].oppo;
                last[ first[y+1].oppo ].a = j;
                last[ first[y+1].oppo ].m = 1;
                last[ first[y+1].oppo ].oppo = y;
            }
            else if(last[y-1].m)
            {
                j = cnt(last[y-1].oppo, y, n);
                ans[i] = ans[i] + j - last[y-1].a;
                last[y].a = j;
                last[y].m = 1;
                last[y].oppo = last[y-1].oppo;
                first[ last[y-1].oppo ].a = j;
                first[ last[y-1].oppo ].m = 1;
                first[ last[y-1].oppo ].oppo = y;
            }
            else
            {
                j = cnt(y,y,n);
                ans[i] = ans[i] + j;
                first[y].m = 1;
                first[y].oppo = y;
                first[y].a = j;
                last[y].a = j;
                last[y].m = 1;
                last[y].oppo = y;
            }
        }
        ball[y]--;
        printf("%d\n",ans[i]);
    }

    return 0;
}
