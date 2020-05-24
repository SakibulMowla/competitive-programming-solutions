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
const ll mod = 1E9;


#define SZ 1000010

bool arr[SZ];
vector <int> prime;

void sieve () {
    int lim = sqrt(1000000);
    arr[1] = 1;
    for (int i = 4; i < 1000000; i+= 2) {
        arr[i] = 1;
    }
    for (int i = 3; i < lim; i += 2) {
        if (!arr[i]) {
            for (int j = i * i; j < 1000000; j += i + i) {
                arr[j] = 1;
            }
        }
    }
    prime.pb(2);
    for (int i = 3; i < 1000000; i += 2) {
        if (!arr[i]) {
            prime.pb(i);
        }
    }
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    sieve();

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int a, b;
        cin >> a >> b;

        int lim = sqrt(b);
        vector <int> cnt(b - a + 5, 0);

        for (int i = 1; i <= lim; i++) {
            ll i2 = (ll)i * (ll)i;
            int strt = (a / i) * i;
            if (strt < a) strt += i;
            for (int j = strt; j <= b; j += i) {
                if (j < i2) continue;
                else if (j == i2) cnt[j-a] += 1;
                else cnt[j-a] += 2;
            }
        }

        int ans = 0;
        for (int i = a; i <= b; i++) {
//            cout << ">> " << i << ' ' << cnt[i-a] << endl;
            ans += !arr[cnt[i-a]];
        }

        cout << ans << endl;
    }

    return 0;
}





