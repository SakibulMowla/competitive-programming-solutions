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
    ll i,j,k,n,r1,r2,l1,l2,p,q;
    string s;
    while(cin >> n)
    {
        cin >> s;
        j = k = 0;
        for(i=0;i<n;i++)
        {
            if(s[i] == 'R' && j == 0)
            {
                j = 1;
                p = i;
                r1 = i;
                while(p < n && s[p] == 'R')
                {
                    if(s[p+1] == 'R') p++;
                    else break;
                }
                r2 = p;
            }
            else if(s[i] == 'L' && k == 0)
            {
                k = 1;
                p = i;
                l1 = i;
                while(p < n && s[p] == 'L')
                {
                    if(s[p+1] == 'L') p++;
                    else break;
                }
                l2 = p;
            }
        }
        r1++;
        r2++;
        l1++;
        l2++;
        if(j == 0)
            cout << l2 << " " << l1-1 << "\n";
        else if(k == 0)
            cout << r1 << " " << r2+1 << "\n";
        else cout << r1 << " " << l1-1 << "\n";
    }

    return 0;
}
