#include <bits/stdc++.h>

using namespace  std;

typedef unsigned long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const ll inf = 1;
const ll mod = 1LL;

//inline void inp( ll &n ){
//    n=0;
//    ll ch=getchar_unlocked();int sign=1;
//    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
//    while(  ch >= '0' && ch <= '9' )
//            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
//    n=n*sign;
//}

#define SZ 1000010
#define MAXX 1E12

bool arr[SZ];
ll prime[SZ/10];
map <ll , int> mp;

void sieve () {
    int k = sqrt(SZ);
    for (ll i = 3; i < k; i += 2)
        if (!arr[i])
            for (ll j = i * i; j < SZ; j += i + i)
                arr[(int)j] = 1;
    int cnt = 0;
    prime[cnt++] = 2;
    for (int i = 3; i < SZ; i += 2)
        if (!arr[i])
            prime[cnt++] = i;
}

void factorize (ll n) {
    for (int i = 0; prime[i] * prime[i] <= n; i++) {
        if (n % prime[i] == 0) {
            int cnt = 0;
            while (n % prime[i] == 0) {
                n /= prime[i];
                cnt++;
            }
            mp[ prime[i] ] += cnt;
        }
    }
    if (n != 1) {
        mp[n]++;
    }
    return;
}

void formatted_print (ll n) {
    int ans = 0;
    for (auto it:mp) {
        ans += it.Y;
    }
    printf("%d\n", ans);
}

int main() {
//    #if defined LOCAL
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
//    #endif

    sieve();

    ll n;
    scanf("%llu", &n);
    factorize(n);
    formatted_print(n);

    return 0;
}







