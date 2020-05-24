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

template <class T> T GCD(T a,T b)
{
    if(b == 0) return a;
    return GCD(b,a%b);
}

template <class T> T LCM(T a,T b)
{
    return (a*b) / GCD(a,b);
}

typedef pair<ll,ll> pii;
const ll inf = 1<<28;
#define MP(a,b) make_pair(a,b)
#define SZ 1010

ll cnt[30];

//%I64d
int main()
{
    ll i,j,k;
    string s;
    while(cin >> s)
    {
        memset(cnt,0,sizeof(cnt));
        k = s.size();
        for(i=0;i<k;i++)
        {
            cnt[s[i]-'a']++;
        }
        j = 0;
        for(i=0;i<26;i++)
            if(cnt[i] % 2)
                j++;
        if(j == 0 || j % 2) printf("First\n");
        else printf("Second\n");
    }

    return 0;
}
