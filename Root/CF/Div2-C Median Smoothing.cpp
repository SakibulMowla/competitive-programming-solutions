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

    int n;
    cin >> n;

    vector <int> a(n), mark(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    mark[0] = mark[n-1] = 1;

    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i+1]) {
            mark[i] = mark[i+1] = 1;
        }
    }

    int ans = 0;

    for (int i = 1; i <= n - 2; i++) if (mark[i] == 0) {
        int j = i;
        while (mark[j] == 0) {
            j++;
        }
        j--;
        int cnt = j - i;
        ans = max(ans, 1 + cnt / 2);
//            cerr << ">> " << strt << ' ' << endd << ' ' << cnt << endl;
        for (int k = 0; i+k <= j-k; k++) {
            a[i+k] = a[i-1];
            a[j-k] = a[j+1];
        }
        i = j;
    }

    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << endl;


    return 0;
}





