#include <bits/stdc++.h>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()

typedef long long ll;
typedef pair<ll,ll> pii;

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){while(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

#define mem(a, b) memset(a, b, sizeof(a))
#define SZ 1010
const ll inf = 1LL<<28;
const ll mod = 1LL;

struct data
{
    char ch;
    ll fre;
};

data arr[30];

ll cnt[30], dp[30][1010], N, ans;

ll solve(ll indx,ll left,ll bri)
{
//    printf("indx %I64d left %I64d bri %I64d\n",indx,left,bri);
    if(indx == N)
    {
//        printf("bri = %I64d\n",bri);
//        return bri;
        return 0;
    }
    if(left == 0)
        return inf;
    if(dp[indx][left] != -1)
    {
        return dp[indx][left];
    }
    ll &ret = dp[indx][left], i, j, k;
    ret = inf;
    for(i=1;i<=left;i++)
    {
        j = (arr[indx].fre/i)+( (arr[indx].fre%i) != 0 );
//        ret = min(ret , max( bri, solve(indx+1, left-i, j)) );
        k = max(j , solve(indx+1, left-i, j));
        ret = min(ret, k);
    }
    return ret;
}

//%I64d
int main()
{
//    freopen("1.txt","r",stdin);
//    freopen("2.txt","w",stdout);
    ll n, i, j, k, val;
    char s[SZ];

    while(scanf("%s %I64d",s,&n) == 2)
    {
        mem(cnt, 0);
        for(i=0; s[i]; i++)
            cnt[ s[i]-'a' ]++;
        j = 0;
        for(i=0; i<26; i++)
            if(cnt[i])
                j++;
        if(j > n)
        {
            printf("-1\n");
            continue;
        }
        mem(dp, -1);
        j = 0;
        for(i=0; i<26; i++)
        {
            if(cnt[i])
            {
                arr[j].ch = i + 'a';
                arr[j].fre = cnt[i];
                j++;
            }
        }
        N = j;
        k = solve(0, n, 0);
        printf("%I64d\n",k);
        val = 0;
        for(i=0;i<N;i++)
        {
            j = arr[i].fre/k + ((arr[i].fre % k) != 0);
            val += j;
            while(j--)
                printf("%c",arr[i].ch);
        }
        while(val < n)
        {
            printf("%c",arr[0].ch);
            val++;
        }
        printf("\n");
    }

    return 0;
}
