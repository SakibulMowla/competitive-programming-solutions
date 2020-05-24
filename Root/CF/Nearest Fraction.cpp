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

double best,besti,bestj,x,y;

template <class T> T GCD(T a,T b)
{
    if(b == 0) return a;
    return GCD(b,a%b);
}

//%I64d
int main()
{
    ll i,j,k,up;
    double n,upper,dif;
    ll tmp;
    while(scanf("%lf %lf %lf",&x,&y,&n) == 3)
    {
        tmp = GCD((ll)x,(ll)y);
        x /= (double)tmp;
        y /= (double)tmp;
        if(x == y)
        {
            printf("1/1\n");
            continue;
        }
        if(n >= y)
        {
            printf("%I64d/%I64d\n",(ll)x,(ll)y);
            continue;
        }
        if(x+1 == y)
        {
            x = n-1;
            y = n;
//            if(x==0) x = 1;
            printf("%I64d/%I64d\n",(ll)x,(ll)y);
            continue;
        }
        best = 1000000000000.0;
        besti = bestj = 0;
        for(i=1; i<=(ll)n; i++)
        {
            upper = (x * (double)i) / y;
            up = floor(upper);
            dif = ((double)up * y) - ((double)i * x);
            if(dif <  0) dif *= -1;
            if(dif < best || (dif == best && (up+i  > besti + bestj)))
            {
                best = dif;
                besti = up;
                bestj = i;
            }

            up--;
            dif = ((double)up * y) - ((double)i * x);
            if(dif <  0) dif *= -1;
            if(dif < best || (dif == best && (up+i  > besti + bestj)))
            {
                best = dif;
                besti = up;
                bestj = i;
            }

            up = ceil(upper);
            dif = ((double)up * y) - ((double)i * x);
            if(dif <  0) dif *= -1;
            if(dif < best || (dif == best && (up+i  > besti + bestj)))
            {
                best = dif;
                besti = up;
                bestj = i;
            }

            up++;
            dif = ((double)up * y) - ((double)i * x);
            if(dif <  0) dif *= -1;
            if(dif < best  || (dif == best && (up+i  > besti + bestj)))
            {
                best = dif;
                besti = up;
                bestj = i;
            }
        }

        tmp = GCD((ll)besti,(ll)bestj);
        besti /= tmp;
        bestj /= tmp;
        if(bestj == 1 && (x/y)-(int)(x/y) == 0.5) besti = besti - 1ll;
        printf("%I64d/%I64d\n",(ll)besti,(ll)bestj);
    }

    return 0;
}
