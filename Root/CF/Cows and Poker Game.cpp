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

typedef pair<ll,ll> pii;
const ll inf = 1<<28;
#define MP(a,b) make_pair(a,b)
#define SZ 1010

//%I64d
int main()
{
    ll i,j,k,a,f;
    string s;
    while(cin >> k >> s)
    {
        a = i = f = 0;
//        k = s.size();
        for(j=0;j<k;j++)
        {
            if(s[j] == 'A') a++;
            else if(s[j] == 'F') f++;
            else i++;
        }
        if(i > 1)  k = 0;
        else if(i == 1) k = 1;
        else k = a;
        cout << k << "\n";
    }

    return 0;
}
