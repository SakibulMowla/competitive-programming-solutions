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

//%I64d
int main()
{
    ll i,j,k,n,len,one,two;
    string s,f,r;

    f= "lala.";
    r= "miao.";

    while(cin >> n)
    {
        getchar();
        for(i=0;i<n;i++)
        {
            getline(cin,s);

            len = s.size();

            if(len < 5)
            {
                cout << "OMG>.< I don't know!\n";
                continue;
            }

            one = two = 0;
            if(s.substr(0,5) == r) two = 1;
            if(s.substr(len-5) == f) one = 1;

            if( (one == 1 && two == 1) || (one == 0 && two==0) )
                cout << "OMG>.< I don't know!\n";
            else if( two== 1)
                cout <<"Rainbow's\n";
            else if( one == 1)
                cout << "Freda's\n";

        }
    }

    return 0;
}
