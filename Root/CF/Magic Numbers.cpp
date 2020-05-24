#include "stdio.h"
#include "string.h"
#include "string"
#include "stdlib.h"
#include "math.h"
#include "map"
#include "vector"
#include "queue"
#include "stack"
#include "set"
#include "iostream"
#include "algorithm"

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()

typedef long long ll;

#define SZ 1010
const ll inf = 1LL<<28;
const ll mod = 1LL;

string arr, a, b, c;



ll n;

ll solve(ll pos)
{
    ll ret = 0;

    ll i,j,k;

    if(pos == n) return 1;

    if(n-pos >= 1)
    {
        if(a == arr.substr(pos,1))
            ret = max(ret, solve(pos+1));
    }

    if(n-pos >= 2)
    {
        if(b == arr.substr(pos,2))
            ret = max(ret, solve(pos+2));
    }

    if(n-pos >= 3)
    {
        if(c== arr.substr(pos,3))
            ret = max(ret, solve(pos+3));
    }

    return ret;
}

//%I64d
int main()
{
    a = "1";
    b = "14";
    c = "144";
    ll i,j,k;
    char s[123];
    while(scanf(" %s",&s) == 1)
    {
        arr = s;
        n = strlen(s);
        if(solve(0)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
