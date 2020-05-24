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

#define SZ 1000010
const ll inf = 1LL<<28;
const ll mod = 1LL;

int k;

struct data
{
    int op,n;
    char ch;
};

data arr[SZ];


void doit(int x,int y)
{
    int i, j, n, m;

    if(x != 0)
    {
        if(x > 0)
        {
            arr[k].op = 1;
            arr[k].n = x;
            arr[k].ch = 'R';
        }
        else
        {
            arr[k].op = 1;
            arr[k].n = -x;
            arr[k].ch = 'L';
        }
        k++;
    }

    if(y != 0)
    {
        if(y > 0)
        {
            arr[k].op = 1;
            arr[k].n = y;
            arr[k].ch = 'U';
        }
        else
        {
            arr[k].op = 1;
            arr[k].n = -y;
            arr[k].ch = 'D';
        }
        k++;
    }

    arr[k].op = 2;
    k++;

    if(y != 0)
    {
        if(y > 0)
        {
            arr[k].op = 1;
            arr[k].n = y;
            arr[k].ch = 'D';
        }
        else
        {
            arr[k].op = 1;
            arr[k].n = -y;
            arr[k].ch = 'U';
        }
        k++;
    }

    if(x != 0)
    {
        if(x > 0)
        {
            arr[k].op = 1;
            arr[k].n = x;
            arr[k].ch = 'L';
        }
        else
        {
            arr[k].op = 1;
            arr[k].n = -x;
            arr[k].ch = 'R';
        }
        k++;
    }



    arr[k].op = 3;
    k++;
}

struct point
{
    int x, y;
};

point data[100010];

bool comp(point p,point q)
{
    if(p.x == q.x)
    {
        if(p.y >=0 && q.y >=0)
            return p.y < q.y;
        if(p.y <0 && q.y <0)
            return p.y > q.y;
        return p.y > q.y;
    }

    if(p.x >= 0 && q.x >= 0)
        return p.x < q.x;
    if(p.x < 0 && q.x < 0)
        return p.x > q.x;

    return p.x > q.x;
}

//%I64d
int main()
{

    int n,m,i,x,y;

    while(scanf("%d",&n) == 1)
    {
        k = 0;

        for(i=0;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            data[i].x = x;
            data[i].y = y;
        }

        sort(data, data+n, comp);

        for(i=0;i<n;i++)
            doit(data[i].x, data[i].y);

        printf("%d\n",k);

        for(i=0;i<k;i++)
        {
            if(arr[i].op == 1)
            {
                printf("%d %d %c\n",1,arr[i].n,arr[i].ch);
            }
            else
                printf("%d\n",arr[i].op);
        }
    }


    return 0;
}

