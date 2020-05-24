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

typedef long long ll;
typedef pair<ll,ll> pii;
const ll inf = 1<<28;
#define MP(a,b) make_pair(a,b)
#define SZ 110

ll matrix[SZ][SZ];

//%I64d
int main()
{
    ll i,j,k,n,m,p,q,t=0;
    while(cin >> n && n)
    {
        cin >> m;
        for(i=0;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
                matrix[i][j] = matrix[j][i] = inf;
            matrix[i][i] = 0;
        }
        while(cin >> p >> q && (p + q))
        {
            matrix[p][q] = 1;
        }
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                {
                    if(matrix[i][j] == inf)
                    {
                        if(matrix[i][k] != inf && matrix[k][j] != inf)
                            matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                    else
                    {
                        if(matrix[i][k] != inf && matrix[k][j] != inf)
                            matrix[i][j] = max(matrix[i][j] , matrix[i][k] + matrix[k][j]);
                    }
                }
        j = 0;
        k = 0;
        for(i=1;i<=n;i++)
        {
//            if(i == 5) printf("drtg = %lld\n",matrix[m][i]);
            if(matrix[m][i] > j && matrix[m][i] < inf)
                j = matrix[m][i] , k = i;
        }
        printf("Case %lld: The longest path from %lld has length %lld, finishing at %lld.\n\n",++t,m,j,k);
    }

    return 0;
}
