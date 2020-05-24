#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;


#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

#define X first
#define Y second

ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

const ll mod = 1000000007LL;

#define SZ  500000+10

ll fact[SZ];
ll store[SZ];

void pre(int n)
{
    int i, k;
    ll five_inv;

    k = min(500000, n);
    fact[0] = 1LL;
    for(i=1; i<=k+5; i++)
        fact[i] = ((ll)i*fact[i-1]) % mod;

    five_inv = BigMod(fact[5], mod-2, mod);
    for(i=0; i<=k; i++)
        store[i] = (((fact[i+5] * BigMod(fact[i], mod-2, mod)) % mod) * five_inv) % mod;

    return;
}

int main() {
    int i, N;
    ll ans;

    while(scanf("%d",&N) == 1)
    {
        N -= 13;
        if(N < 0)
        {
            puts("0");
            continue;
        }

        pre(N);
        ans = 0;

        if(N&1)
            for(i=1; i<=N; i+=2)
                ans = (ans + store[(N-i)/2]) % mod;
        else
            for(i=0; i<=N; i+=2)
                ans = (ans + store[(N-i)/2]) % mod;

        printf("%lld\n",ans);
    }

    return 0;
}














