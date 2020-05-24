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

vector <ll> input;

//%I64d
int main()
{
    ll i,j,k,n,m;
    while(cin>>n)
    {
        input.clear();
        for(i=0;i<n;i++)
        {
            cin >>j;
            input.push_back(j);
        }
        sort(input.begin(),input.end());
        k = input[0];
        j = 0;
        for(i=0;i<n;i++)
        {
            if(input[i] % k == 0) j++;
            else break;
        }
        if(j == n) cout << k << endl;
        else cout << "-1\n";
    }

    return 0;
}
