#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define mem(a,b) memset(a, b, sizeof(a))

ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

const ll mod = 1000000007LL;

#define SZ 110

char arr[SZ];
int KK;
ll dp[1150][110][12];
ll len_cnt[1150];

ll rec(int len, int k, int m){
    if(len == 0) return (ll)(k==0);
    if(k == 0) return 0LL;

    ll &ret = dp[len][k][m];
    if(~ret) return ret;

    int i;
    ret = 0LL;

    for(i=1; i<=min(m, len); i++){
        ret = (ret + ( BigMod(25, i-1, mod) * rec(len-i, k-1, m)) % mod ) % mod;
    }

    return ret;
}

ll BigMod(int n){
    ll ret = (BigMod(26, n+1, mod) - BigMod(25, n+1, mod) + mod) % mod;
    return ret;
}

int main(){
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("3.txt", "w", stdout);
    #endif // defined

    mem(dp, -1);
    int test=0, t, n, m, i, j, k;
    ll ans;

    scanf("%d",&t);

    while(t--){
        scanf("%s",arr);
        KK = strlen(arr);
        scanf("%d %d",&m,&n);


        for(i=KK; i<=(m*KK)+1; i++){
            len_cnt[i] = rec(i-1, KK-1, m);
        }

        ans = 0LL;

        for(i=KK; i<=(m*KK)+1; i++){
            ans = (ans + (len_cnt[i] * BigMod(n-i)) % mod ) % mod;
        }

        ans = (BigMod(26, n, mod) - ans + mod ) % mod;

        printf("Case %d: %lld\n",++test, ans);
    }


    return 0;
}
