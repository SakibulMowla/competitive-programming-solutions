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

//%I64d
int main()
{
    ll n,i,j,f;
    set <ll> ans ;
    vector <ll> a , b , c;

    while(cin >> n)
    {
        ans.clear();
        a.clear();
        b.clear();
        c.clear();

        for(i=0;i<n;i++)
        {
            cin >> j;
            if(j == 0 || j == 100)
                ans.insert(j);
            else if(j < 10)
                a.push_back(j);
            else if(j % 10 == 0)
                b.push_back(j);
            else
                c.push_back(j);
        }

        f = 0;

        if(a.size())
        {
            ans.insert(a[0]);
            f = 1;
        }

        if(b.size())
        {
            ans.insert(b[0]);
            f = 1;
        }

        if(!f && c.size())
        {
            ans.insert(c[0]);
        }

        printf("%d\n",ans.size());

        for(set<ll>::iterator it = ans.begin();it!=ans.end();it++)
            cout << (*it) << " ";
        cout << "\n";
    }

    return 0;
}
