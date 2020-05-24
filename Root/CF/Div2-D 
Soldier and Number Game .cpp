#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;
using pll = pair <ll , ll>;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 5000000+10

bool arr[SZ];
vector <int> prime;

void sieve () {
	int lim = sqrt(SZ) + 2;
	for (int i = 3; i < lim; i++) {
		if (!arr[i]) {
			for (int j = i * i; j < SZ; j += i + i) {
				arr[j] = 1;
			}
		}
	}
	prime.pb(2);
	for (int i = 3; i < SZ; i+= 2) {
		if (!arr[i]) {
			prime.pb(i);
		}
	}
	return;
}

ll Divisors (int n) {
	ll ans = 0;
	for (int i = 0; i < sz(prime) && (ll)prime[i] * prime[i] <= (ll)n; i++) {
		if (n % prime[i] == 0) {
			while (n % prime[i] == 0) {
				n /= prime[i];
				ans++;
			}
		} 
	}
	if (n != 1) ans++;
	return ans;
}

ll sum[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif
	
	sieve();
	
	for (int i = 2; i < SZ; i++) {
		sum[i] = sum[i-1] + Divisors(i);
	}	
	
	int t;
	scanf("%d", &t);
	
	for (int cs = 0; cs < t; cs++) {
		int a, b;
		scanf("%d %d", &a, &b);
		//cerr << ">> " << sum[a] << ' ' << sum[b] << endl;
		printf("%I64d\n", sum[a] - sum[b]);
	}
	
    return 0;
}






