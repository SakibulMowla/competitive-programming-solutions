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

//ll bigmod(ll a,ll b,ll m)
//{
//    if(b == 0) return 1%m;
//    ll x = bigmod(a,b/2,m);
//    x = (x * x) % m;
//    if(b % 2 == 1) x = (x * a) % m;
//    return x;
//}

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
#define SZ 50

ll par[SZ] , col[SZ] , cycle[SZ];
vector <ll> ans[SZ];

ll find(ll r)
{
    if(r == par[r]) return r;
    return par[r] = find(par[r]);
}



void init(ll n)
{
    ll i;
    for(i=0; i<=n; i++)
    {
        par[i] = i;
        cycle[i] = 1;
        col[i] = 0;
        ans[i].clear();
    }
}

ll print(ll n)
{
    ll i,j;
    for(i=1; i<=n; i++)
    {
        printf("i = %I64d col[i] = %I64d\n",i,col[i]);
        if(col[i] == 0)
        {
            col[i] = 1LL;
            return i;
        }
    }
//    printf("dsfjk\n");
    return -1;
}

//%I64d
int main()
{
    ll i,j,k,n,m,x,y;
    while(cin >> n >> m)
    {
        init(n);
        for(i=0; i<m; i++)
        {
            cin >> j >> k;
            x = find(j);
            y = find(k);
            if(x == y) continue;
            else if(cycle[x] + cycle[y] > 3)
            {
//                printf("1\n");
                printf("-1\n");
                return 0;
            }
            else if(par[j] == j && par[k] == k && cycle[j] + cycle[k] == 2)
            {
//                printf("2\n");
                par[k] = j;
                cycle[j] = 2;
                ans[j].push_back(j);
                ans[j].push_back(k);
                col[j] = col[k] = 1;
            }

            else if(par[j] == j)
            {
//                printf("3\n");

                if(cycle[x] > cycle[y])
                {
                    par[y] = x;
                    cycle[x]++;
                    ans[x].push_back(k);
                }
                else
                {
                    par[x] = y;
                    cycle[y]++;
                    ans[y].push_back(j);
                }
                col[j] = col[k] = 1;
            }

            else if(par[k] == k)
            {
//                printf("4\n");

                if(cycle[x] > cycle[y])
                {
                    par[y] = x;
                    cycle[x]++;
                    ans[x].push_back(k);
                }
                else
                {
                    par[x] = y;
                    cycle[y]++;
                    ans[y].push_back(j);
                }
                col[k] = col[j] = 1;
            }

            else
            {
//                printf("5\n");
                printf("-1\n");
                return 0;
            }
        }

//        for(i=1;i<=n;i++)
//            printf("i = %I64d col[i] = %I64d\n",i,col[i]);
//
        j = 0;
        vector <ll> final;
        final.clear();
//        printf("yes\n");
        for(i=1; i<=n; i++)
        {
            if(par[i] == i)
            {
                if(ans[i].size() == 3)
                {
//                    printf("yes1\n");
                    final.push_back( ans[i][0] );
                    final.push_back( ans[i][1] );
                    final.push_back( ans[i][2] );
//                    cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << "\n";
                }
                j += 3;
            }
            if(par[i] == i)
            {
                else if(ans[i].size() == 2)
                {
                    printf("yes2 i = %I64d\n",i);
                    final.push_back( ans[i][0] );
                    final.push_back( ans[i][1] );
                    k = print(n);
                    if(k == -1)
                    {
                        printf("-1\n");
                        return 0;
                    }
                    else
                        final.push_back(k);
                    printf("yes2 i = %I64d\n",i);
//                    cout << print(n) << "\n";
                }
                j += 3;
            }
            if(par[i] == i)
            {
                else if(ans[i].size() == 0)
                {
//                    printf("yes\n");
                    k = print(n);
                    if(k == -1)
                    {
                        printf("-1\n");
                        return 0;
                    }
                    else
                        final.push_back(k);

                    k = print(n);
                    if(k == -1)
                    {
                        printf("-1\n");
                        return 0;
                    }
                    else
                        final.push_back(k);

                    k = print(n);
                    if(k == -1)
                    {
                        printf("-1\n");
                        return 0;
                    }
                    else
                        final.push_back(k);
//                    printf("yes3\n");
//                    cout << print(n) ;
//                    cout << " " << print(n);
//                    cout << " " << print(n) << "\n";
                }
                j += 3;
            }
        }
        if(j == n) break;

    }

//        printf("yes\n");

    for(i=0; i<final.size(); i++)
    {
        cout << final[i] << " ";
        if((i%3) == 2) printf("\n");
    }

}

return 0;
}

/*

12 4
1 2
4 5
7 8
10 11

*/
