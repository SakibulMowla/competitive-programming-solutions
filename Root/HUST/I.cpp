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
#define SZ 210

ll matrix[SZ][SZ] , n;

ll non_intersecting(ll u,ll v)
{
    ll i,j,p,q;
    p = u;
    for(i=0;i<n;i++)
        if(matrix[u][i] < matrix[v][i] && matrix[u][i] > matrix[u][p])
            p = i;
    q = u;
    for(i=0;i<n;i++)
        if(matrix[u][i] < matrix[v][i] && matrix[p][i] > matrix[p][q])
            q = i;
//    cout << "pq = "  << matrix[p][q] << "\n";
    return matrix[p][q];
}

//%I64d
int main()
{
    ll i,j,k;
    while(cin >> n)
    {
        for(i=0;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
                matrix[i][j] = matrix[j][i] = inf;
            matrix[i][i] = 0;
        }
        for(i=0;i<n-1;i++)
        {
//            cout << "i = " << i << "\n";
            cin >> j >> k;
            matrix[--j][--k] = matrix[k][j] = 1;
        }
        for(k=0;k<n;k++)
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
        k = 0;
        for(i=0;i<n;i++)
            for(j=0;j<i;j++)
                if(matrix[i][j] == 1)
                    /*cout << k << "\n" ,*/ k = max(k , non_intersecting(i,j) * non_intersecting(j,i) )  ;
        cout << k << "\n";
    }

    return 0;
}
