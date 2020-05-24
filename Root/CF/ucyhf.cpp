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
#define SZ 50000

ll arr[SZ];
vector <ll> prime;

void sieve()
{
    ll i,j,k;
    arr[0] = arr[1] = 1;
    for(i=4;i<SZ;i+=2) arr[i] = 1;
    for(i=3;i<sqrt(SZ);i+=2)
        if(arr[i] == 0)
            for(j=i*i;j<SZ;j+=i+i)
                arr[j] = 1;
//    prime.push_back(2);
    for(i=13;i<SZ;i+=2)
        if(arr[i] == 0)
            prime.push_back(i);
}

//%I64d
int main()
{
    ll i,j,k,n,l;
    cin >> n;
    k = 0;
    sieve();
    for(i=0;i<prime.size();i++)
    {
        j = prime[i];
        l = 0;
        while(j)
        {
            l = (l*10) + (j%10);
            j /= 10;
        }
        if(arr[l] == 0 && l!=prime[i]) k++;
        if(k == n)
        {
            cout << prime[i];
            return 0;
        }
    }

    return 0;
}
