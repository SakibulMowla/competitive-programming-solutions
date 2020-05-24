#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  3010

bool arr[SZ];
vector <int> prime;

void sieve () {
    int k = sqrt(SZ);
    for (int i = 3; i < k; i += 2)
        if (!arr[i])
            for (ll j = (ll)i * (ll)i; j < SZ; j += i + i)
                arr[j] = 1;
    prime.pb(2);
    for (int i = 3; i < SZ; i += 2)
        if (!arr[i])
            prime.pb(i);
//    for (int i = 0; i < 25; i++)
//        cout << prime[i] << " ";
}

bool factorize (int n) {
    int cnt = 0;
    for (int i = 0; i < sz(prime) && (ll)prime[i] * (ll)prime[i] <= (ll)n; i++) {
        if (n % prime[i] == 0) {
            cnt++;
            while (n % prime[i] == 0) n /= prime[i];
            if (cnt > 2) return true;
        }
    }
    if (n != 1) cnt++;
    return (cnt > 2);
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    sieve();

    vector <int> a(1000);
    int cnt = 0;
    for (int i = 30; i < 2665; i++) {
        if (factorize(i)) {
            a[cnt++] = i;
            if (cnt == 1000)
                break;
        }
    }

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;
        cout << a[n-1] << '\n';
    }

    return 0;
}




