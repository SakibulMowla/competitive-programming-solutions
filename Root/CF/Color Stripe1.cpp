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
    ll i,j,k,l,cnt1,cnt2,cnt,n;
    string s1,s2,s;
    while(cin >> n >> k)
    {
        cin >> s;
        if(k == 2)
        {
            cnt1 = cnt2 = 0;
            s1 = "" , s2 = "";
            for(i=0;i<n;i++)
            {
                s1 += 'A' + (i%2);
                s2 += 'A' + !(i%2);
                if(s1[i] != s[i]) cnt1++;
                if(s2[i] != s[i]) cnt2++;
            }
            if(cnt1<cnt2) cout << cnt1 << "\n" << s1 << "\n";
            else cout << cnt2 << "\n" << s2 << "\n";
        }
        else
        {
            cnt = 0;
            for(i=1;i<n;i++)
            {
                if(s[i] == s[i-1])
                {
                    cnt++;
                    j = (s[i] - 'A' + 1) % k;
                    if(i+1 < n)
                    {
                        l = s[i+1] - 'A';
                        if(j == l) j++ , j %= k;
                    }
                    s[i] = 'A' + j;
                }
            }
            cout << cnt << "\n" << s << "\n";
        }
    }

    return 0;
}
