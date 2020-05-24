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

//template <class T> T GCD(T a,T b)
//{
//    if(b == 0) return a;
//    return GCD(b,a%b);
//}
//
//template <class T> T LCM(T a,T b)
//{
//    return (a*b) / GCD(a,b);
//}

typedef pair<ll,ll> pii;
const ll inf = 1LL<<28;
#define MP(a,b) make_pair(a,b)
#define SZ 1010

//%I64d
int main()
{
    ll i,j,k,n,m,p;
    string s;
    while(cin >> n >> k)
    {
        cin >> s;
        p = s.size();
        for(i=0;i<p;i++)
        {
            if(s[i+1] == '.') continue;
            else if(i + 1 < p)
            {
                m = 0;
                for(j=i+k;j>i;j--)
                {
                    if(j >= p) continue;
                    if(s[j] == '.')
                    {
                        i = j-1;
                        m = 1;
                        break;
                    }
                }
                if(m == 0)
                {
                    printf("NO\n");
                    return 0;
                }
            }
        }
        if(i == p)
        printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
