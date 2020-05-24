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
#define SZ 1010

//%I64d
int main()
{
    ll i,j,k,n,m,p,ne,ze;
    vector <ll> v,v1,v2,v3;
    while(cin >> n)
    {
        p = ne = ze = 0;
        for(i=0; i<n; i++)
        {
            cin >> j;
            if(j < 0 && ne == 0)
            {
                v1.push_back(j);
                ne++;
            }
            else if(j == 0 || j < 0)
            {
                v3.push_back(j);
                ze++;
            }
            else
            v.push_back(j);
        }
        cout << "1 ";
        cout << v1[0] << "\n";
        k = v.size();
        m = 0;
        if(k == 0)
        {
            m = 2;
            k += 2;
            sort(v3.begin(),v3.end());
            v.push_back(v3[0]);
            v.push_back(v3[1]);
        }
        cout << k << " ";
        for(i=0;i<k;i++)
            cout << v[i] << " ";
        cout << "\n";
        cout << ze-m << " ";
        for(i=m;i<ze;i++)
        {
            cout << v3[i] << " ";
        }
        printf("\n");
    }

    return 0;
}
