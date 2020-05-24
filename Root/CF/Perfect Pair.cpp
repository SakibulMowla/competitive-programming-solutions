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


int main()
{
    ll n, m, a, b, c, step, k, p;


    while(cin >> a >> b >> m)
    {
        if(a > b) swap(a,b);
        if(a>=m || b>=m)
        {
            cout << "0\n";
            continue;
        }
        if(a<=0 && b<=0)
        {
            printf("-1\n");
            continue;
        }

        step = 0;

        if(a < 0)
        {
            step += (-a/b);
            a = a +(step*b);
            if(a<0)
            {
                a += b;
                step++;
            }
        }

        if(a > b) swap(a,b);

        k = 1;
        p = a;

        while(b < m)
        {
            c = b;
            b = a + b;
            a = c;
            step++;
        }

        cout << step << "\n";

    }

    return 0;
}
