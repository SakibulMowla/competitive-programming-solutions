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


#define SZ 100010


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    vector <int> prime;

    for (int i = 2; i <= 1000; i++) {
        bool flag = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            prime.pb(i);
        }
    }

    int n;
    cin >> n;

    vector <bool> mark(1001, false);
    for (int i = 2; i <= 1000; i++) {
        int x = i;
        for (int j = 0; prime[j] * prime[j] <= x; j++) {
            if (x % prime[j] == 0) {
                int num = 1;
                while (x % prime[j] == 0) {
                    x /= prime[j];
                    num *= prime[j];
                }
                mark[num] = true;
            }
        }
        if (x != 1) {
            mark[x] = true;
        }
    }

    vector <int> a;
    for (int i = 1; i <= n; i++) {
        if (mark[i]) {
            a.pb(i);
        }
    }

    cout << sz(a) << endl;
    for (int i = 0; i < sz(a); i++) {
        cout << a[i] << ' ';
    }
    cout << endl;

    return 0;
}





