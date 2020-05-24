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

//ll bigmod(ll a,ll b,ll m)
//{
//    if(b == 0) return 1%m;
//    ll x = bigmod(a,b/2,m);
//    x = (x * x) % m;
//    if(b % 2 == 1) x = (x * a) % m;
//    return x;
//}
//
//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way
//
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
#define SZ 1010

vector <pii> V;

ll B_search(ll p)
{
    ll i,j,start,end,mid;
    start = 0;
    end = V.size() - 1;
    while(start <= end)
    {
        mid = (start+end) / 2;
        if(V[mid].first <= p && V[mid].second >= p)
            return mid + 1;
        if(V[mid].second < p)
            start = mid+1;
        else
            end = mid-1;

    }
    return -1;
}

//%I64d
int main()
{
    ll n,m,i,j,k,p,start,tim;
    while(cin >> n >> m)
    {
        V.clear();
        start = 1;
        tim = 0;
        for(i=0;i<n;i++)
        {
            cin >> j >> k;
            p = j * k;
            tim += p;
            V.push_back( MP(start,tim) );
            start = tim + 1;
        }
        while(m--)
        {
            cin >> j;
            cout << B_search(j) << endl;
        }
    }

    return 0;
}
