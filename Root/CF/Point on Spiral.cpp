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
typedef long long ll;
ll X[] = {1,0,-1,0};//4-way
ll Y[] = {0,1,0,-1};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way


typedef pair<ll,ll> pii;
const ll inf = 1<<28;
#define MP(a,b) make_pair(a,b)
#define SZ 1010

ll dx,dy;

bool inside(ll a,ll b,ll c,ll d,ll indx)
{
    if(indx == 0) {if(dy == b && (dx >= a && dx <= c)) return true;}
    else if(indx == 1) {if(dx == a && (dy >= b && dy <= d)) return true;}
    else if(indx == 2) {if(dy == b && (dx >= c && dx <= a)) return true;}
    else if(indx == 3) {if(dx == a && (dy >= d && dy <= b)) return true;}
    return false;
}

//%I64d
int main()
{
    ll x,y,i,j,turn,mul,indx;
    while(scanf("%I64d %I64d",&dx,&dy) == 2)
    {
        x = y = turn = indx = 0;
        mul = 1;
        while(x != dx || y != dy)
        {
            i = x + X[indx] * mul;
            j = y + Y[indx] * mul;
            if(inside(x,y,i,j,indx)) break;
            if(turn % 2 == 1) mul++;
            turn++;
            indx++;
            indx %= 4;
            x = i;
            y = j;
        }
        printf("%I64d\n",turn);
    }

    return 0;
}
