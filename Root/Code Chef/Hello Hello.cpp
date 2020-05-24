#include <bits/stdc++.h>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()

typedef long long ll;
typedef pair<ll,ll> pii;

template <class T> T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

#define SZ 1010
const ll inf = 1LL<<28;
const ll mod = 1LL;

struct DAATAA
{
    ll month, inst;
    double rate;
};

DAATAA ARRAY[110];

//%I64d
int main()
{
    ll n, t, i, l, min, num;
//    freopen("1.txt","r",stdin);
    double cost, now;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lf %lld %lld",&ARRAY[0].rate,&min,&n);
        l = 1LL;
        for(i=1;i<=n;i++)
            scanf("%lld %lf %lld",&ARRAY[i].month,&ARRAY[i].rate,&ARRAY[i].inst),
            l = lcm(l, ARRAY[i].month);
        cost = (double)l * (double)min * ARRAY[0].rate;
        num = 0;
        for(i=1;i<=n;i++)
        {
            now = ARRAY[i].rate * (double)l * (double)min;
            now += (double)ARRAY[i].inst * (l / ARRAY[i].month);
            if(now < cost)
            {
                cost = now;
                num = i;
            }
        }
        printf("%lld\n",num);
    }


    return 0;
}
