#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define pb push_back

#define SZ  2703666+10
#define SZ1 10000000+10

bool arr[SZ];
vector <int> prime;
int dp[SZ];
int str[SZ];

void sieve(){
    int i, k;
    ll j;

    k = sqrt(SZ);

    for(i=3;i<=k;i++)
        if(!arr[i])
            for(j=(ll)i*(ll)i; j<(ll)SZ; j+=(ll)i+(ll)i)
                arr[j] = 1;

    prime.pb(2);
    for(i=3; i<SZ; i+=2)
        if(!arr[i])
            prime.pb(i);
}

int f(int num){
    int i, j, k, ret = 0;

    j = num;
    k = sz(prime);

    for(i=0;i<k && (ll)prime[i]*(ll)prime[i] <= (ll)num && num!=1; i++){
        if(str[num] != -1) return str[j] = str[num] + ret;
        if(num % prime[i] == 0){
            while(num % prime[i] == 0){
                ret++;
                num /= prime[i];
                if(str[num] != -1)
                    return str[j] = str[num] + ret;
            }
        }
    }

    if(num != 1)
        ret++;

    return str[j] = ret;
}

//lo = 0
//hi = 2703665

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    sieve();
    int test=0, i, lo, hi, mid, ans, n;

    mem(str, -1);
    dp[0] = dp[1] = 0;
    str[0] = str[1] = 0;

    REP1(i, 2, SZ-2){
        dp[i] = dp[i-1] + f(i);
        if(dp[i] >= SZ1)
            break;
    }

    while(scanf("%d",&n) == 1 && (n >= 0)){

        lo = 0;
        hi = 2703665;
        ans = -1;

        if(n == 0){
            ans = 0;
            goto HELL;
        }

        while(lo <= hi){
            mid = (lo + hi) >> 1;
            if(dp[mid] == n){
                ans = mid;
                break;
            }
            else if(dp[mid] > n)
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        HELL:;
        printf("Case %d: ",++test);
        ans == -1 ? printf("Not possible.\n") : printf("%d!\n",ans);
    }

    return 0;
}






