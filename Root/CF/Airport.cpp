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

typedef long long ll;
typedef pair<ll,ll> pii;
const ll inf = 1<<28;
#define MP(a,b) make_pair(a,b)
#define SZ 1010
ll seat[SZ];
priority_queue <int> pq;
//%I64d
int main()
{
    ll n,m,i,j,k,maxim,minim;
//    while(1)
    {
        scanf("%I64d %I64d",&n,&m);
        for(i=0;i<m;i++) scanf("%I64d",&seat[i]) , pq.push(seat[i]);
        sort(seat,seat+m);
        maxim = minim = k = 0;
        for(i=0;i<m;i++)
        {
            k += seat[i];
            minim += (seat[i]*(seat[i]+1)) / 2;
            if(k >= n)
            {
                minim -= ((k-n)*(k-n+1)) / 2;
                break;
            }
        }
        while(n--)
        {
            j = pq.top();
            pq.pop();
            maxim += j;
            j--;
            pq.push(j);
        }
        printf("%I64d %I64d\n",maxim,minim);
    }

    return 0;
}
