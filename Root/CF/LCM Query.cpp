#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int, int>;
using pll = pair <ll, ll>;

const ll inf = 1;
const ll mod = 1E9+7;


#define SZ 100010

vector <int> primes;

struct Solve {
    int n, m;
    vector <ll> a, ans;
    vector <int> cnt;

    Solve (int n, int m): n(n), m(m), a(n), ans(n), cnt(17, 0) {
        for (auto &x: a) {
            cin >> x;
        }
        process();
        FindAnswers();
    }

    void process () {
        for (int i = 0; i < n; i++) {
            if (i) ans[i] = ans[i-1];
            else ans[i] = 1;
            for (int j = 0; j < sz(primes); j++) {
                int k = 0;
                while (a[i] % primes[j] == 0) {
                    k++;
                    a[i] /= primes[j];
                }
                if (k > cnt[j]) {
                    for (int x = cnt[j]; x < k; x++) {
                        ans[i] = (ans[i] * (ll)primes[j]) % mod;
                    }
                    cnt[j] = k;
                }
            }
        }
    }

    void FindAnswers () {
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            cout << ans[x-1] << endl;
        }
    }
};

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    for (int i = 2; i <= 60; i++) {
        bool flag = true;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            primes.pb(i);
        }
    }

    int n, m;
    cin >> n >> m;
    Solve Task(n, m);

    return 0;
}


