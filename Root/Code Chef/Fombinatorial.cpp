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

ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define SZ  100010

bool a[SZ];
vector <int> prime;
map <int , int> mp; /// prime, serial no. of that prime
int prime_upto[SZ];

void sieve () {
    a[0] = a[1] = 1;
    for (int i = 4; i <= 1E5; i += 2)
        a[i] = 1;
    int k = sqrt(1E5);
    for (int i = 3; i <= k; i++)
        if(!a[i])
            for (int j = i*i; j <= 1E5; j += i+i)
                a[j] = 1;

    prime.pb(0);
    prime.pb(2);
    mp[2] = 1;
    prime_upto[0] = prime_upto[1] = 0;
    prime_upto[2] = 1;

    for (int i = 3; i <= 1E5; i += 2) {
        prime_upto[i] = prime_upto[i-1];
        if(!a[i]) {
            prime.pb(i);
            prime_upto[i]++;
            mp[i] = prime_upto[i];
        }
        prime_upto[i+1] = prime_upto[i];
    }

    return;
}

/// Prime Upto 100000 = 9592

ll cnt[10000];
ll tree[4*10000];
ll mod;

void Update (int node, int b, int e, int x, int val) { /// node, begin, end, node to update, val to update
    if(b == e) {
        cnt[b] += (ll)val;
        tree[node] = BigMod((ll)prime[b], (ll)cnt[b], mod);
        return;
    }

    int mid = (b + e) >> 1;
    if(x <= mid) Update(2*node, b, mid, x, val);
    else Update(2*node+1, mid+1, e, x, val);

    tree[node] = (tree[2*node] * tree[2*node+1]) % mod;
    return;
}

void Factorize (int N, int n, int dir) {
    int tmpn = n;

    for (int i = 1; prime[i] * prime[i] <= n && a[n]; i++) {
        if(n % prime[i] == 0) {
            int pwr = 0;
            while (n % prime[i] == 0) {
                n /= prime[i];
                pwr++;
            }
            pwr *= tmpn;
            Update(1, 1, prime_upto[N], i, pwr * dir);
        }
    }
    if (n != 1) {
        Update(1, 1, prime_upto[N], mp[n], tmpn * dir);
    }

    return;
}

ll ans[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve();

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, q;
        cin >> n >> mod >> q;

        for (int i = 0; i <= prime_upto[n]; i++)
            cnt[i] = 0LL;
        for (int i = 0; i <= prime_upto[n]*4; i++)
            tree[i] = 1LL % mod;

        for (int i = 1; i <= n/2; i++) {
            Factorize(n, n-i+1, 1);
            Factorize(n, i, -1);
            ans[i] = tree[1];
        }

        while (q--) {
            int r;
            cin >> r;
            if(r > n/2) r = n - r;
            cout << ans[r] << '\n';
        }
    }

    return 0;
}


