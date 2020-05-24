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
    ll i,j,k,n,n1,n2,s1,s2,t1,t2,p;
    string s;
    char c1,c2;
    while(cin >> n >> s1 >> s2 >> t1 >> t2)
    {
        cin >> s;
        n1 = n2 = 0;
        n1 = s1 - t1;
        if(n1 > 0)
        c1 = 'W';
        if(n1 < 0)
        {
            n1 *= -1;
            c1 = 'E';
        }

        n2 = t2 - s2;
        if(n2 > 0)
        c2 = 'N';
        if(n2 < 0)
        {
            n2 *= -1;
            c2 = 'S';
        }
        j = k = 0;
        p = 0;
//        cout << n1 << n2 << c1 << c2 <<  "\n";
        for(i=0;i<n;i++)
        {
            if(s[i] == c1 && j < n1)
            {
                j++;
            }
            if(s[i] == c2 && k < n2)
            {
                k++;
            }
            if(j == n1 && k == n2)
            {
                p = i + 1;
                break;
            }
        }
        if(p) cout << p << "\n";
        else cout << "-1\n";
    }

    return 0;
}
