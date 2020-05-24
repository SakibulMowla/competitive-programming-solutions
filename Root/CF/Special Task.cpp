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
//    while(b == 0) return a;
//    return gcd(b,a%b);
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

int mark[300];

//%I64d
int main()
{
    ll n, m, i, j, k, ans, chalu,zero;

    string s;

    while(cin >> s)
    {
        chalu = 10;
        zero = 0;
        memset(mark,0,sizeof(mark));
        k = s.size();
        ans =1;
        for(i=0;i<k;i++)
        {
            if(s[i] == '?')
            {
                if(i == 0) ans *= (10-1);
                else zero++;
            }
            else if(s[i] >= '0' && s[i] <= '9')
            {
                ans *= 1;
            }
            else
            {
                if(mark[ s[i] ] == 0)
                {
                    mark[ s[i] ] = 1;
                    if(i == 0) ans *= (chalu-1);
                    else ans *= chalu;
                    chalu--;
                }
            }
        }

        cout << ans;
        for(i=0;i<zero;i++)
            printf("0");
        printf("\n");
    }

    return 0;
}
