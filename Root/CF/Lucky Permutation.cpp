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
#define SZ 100010

ll arr[SZ];

//%I64d
int main()
{
    ll n,m,i,j,k,cnt,kotha,pos;
    while(cin >> n)
    {
        if(n == 1)
        {
            cout << "1\n";
            continue;
        }
        else if(n == 2 || n==3)
        {
            cout << "-1\n";
            continue;
        }
        memset(arr,0,sizeof(ll)*(n+2));
        arr[1] = 2;
        cnt = 1;
        pos = 1;
        kotha = n - pos + 1;
        pos = 2;
        k = n;
        for(i=1;i<=ceil(n/2);i++)
        {
            if(i%2)arr[i] = pos,pos+=2;
            else arr[i] = k,k-=2;
        }
        k = n - 1;
        pos = 1;
        for(i=1;i<=ceil(n/2);i++)
        {
            j = n - i + 1;
            if(i%2) arr[j] = k , k -= 2;
            else arr[j] = pos , pos += 2;
        }
        if(n%2)
            arr[n/2+1] = n/2+1;
        if(n%2 && n>5)
            arr[n/2] = n/2+2 , arr[n/2+2] = n/2;
//        else
//            arr[n/2] =  n/2+1,  arr[n/2+1] = n/2;

//        while(cnt <= n && arr[pos] == 0)
//        {
//            cnt++;
//            arr[pos] = kotha;
//            k = pos;
//            pos = kotha;
//            kotha = n - k + 1;
//        }
        for(i=1;i<=n;i++)
            cout << arr[i] << " ";
        cout << "\n";
    }

    return 0;
}
