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
const ll mod = 1E9 + 7;


#define SZ 10000010

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <int> a(n);
    int sum = 0;

    for (auto &x: a) cin >> x, sum += x;

    cout << fixed << setprecision(1);
    cout << (1.0 * sum / n) << endl;

    sort(a.begin(), a.end());

    double median;
    if (n & 1) {
        median = a[n / 2];
    } else {
        median = (a[n / 2] + a[n / 2 - 1]) / 2.0;
    }

    cout << median << endl;

    int frequency = 0;
    int mode;

    for (int i = 0; i < n; i++) {
        int j = i;
        while (j + 1 < n && a[j + 1] == a[i]) j++;
        if (j - i + 1 > frequency) {
            frequency = j - i + 1;
            mode = a[i];
        }
        i = j;
    }

    cout << mode << endl;

    return 0;
}




