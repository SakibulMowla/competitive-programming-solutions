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
    ll i,j,k,n,m,adj,f,s,one,two;
    string s1,s2;
    while(cin >> n)
    {
        cin >> s1 >> s2;
        adj = f = s = 0;
        for(i=0;i<(2*n);i++)
        {
            if(s1[i] == '1' && s2[i] == '1') adj++;
            else if(s1[i] == '1') f++;
            else if(s2[i] == '1') s++;
        }
        one = two = 0;
        if(adj % 2 == 1) {one++;i=0;}
        else i = 1;
        while(f || s)
        {
            if(i == 0)
            {
                if(s)
                {
                    s--;
                    two++;
                }
                else
                {
                    if(f)
                        f--;
                }
            }

            if(i == 1)
            {
                if(f)
                {
                    f--;
                    one++;
                }
                else
                {
                    if(s)
                        s--;
                }
            }
            i = !i;
        }
        if(one > two) printf("First\n");
        else if(one == two) printf("Draw\n");
        else printf("Second\n");
    }

    return 0;
}
