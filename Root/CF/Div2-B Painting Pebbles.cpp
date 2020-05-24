#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 110

int a[SZ];
int b[SZ];
int c[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    FAST

    int n, k;
    cin >> n >> k;

    int mx = 0;
    int mn = 1e9;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }

    int lft = mx;
    int rht = mn;
    bool flag = 0;


    for (int i = 0; i < k; i++) {
        b[i] = mx / k;
        c[i] = mn / k;
        lft -= mx / k;
        rht -= mn / k;
    }

    for (int i = 0; i < k; i++) {
        if (lft) {
            lft--;
            b[i]++;
        }
        if (rht) {
            rht--;
            c[i]++;
        }
    }

    for (int i = 0; i < k; i++) {
        if (abs(b[i]-c[i]) > 1) {
            flag = 1;
            break;
        }
     }

    if (flag) {
        cout << "NO\n";;
        return 0;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        int bb = a[i];
        for (int j = 0; j < k; j++) {
            b[j] = a[i] / k;
            bb -= a[i] / k;
        }
        for (int j = 0; j < k; j++) {
            if (bb) {
                bb--;
                b[j]++;
            }
        }
        for (int j = 0; j < k; j++) {
            while (b[j]) {
                b[j]--;
                cout << j + 1 << ' ';
            }
        }
        cout << '\n';
    }


    return 0;
}







