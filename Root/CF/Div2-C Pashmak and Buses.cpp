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

#define SZ 100010

int a[1010][1010];
bool flag;
vector <int> tmp;

void Backtrack (int d, int &n, int k) {
    if (!d) {
        for (int i = 1; i <= sz(tmp); i++) {
            a[i][n] = tmp[i-1];
        }
        n--;
        if (!n) flag = 1;
        return;
    }
    for (int i = 1; i <= k; i++) {
        tmp.pb(i);
        Backtrack(d-1, n, k);
        if (flag) return;
        tmp.pop_back();
    }
    return;
}

bool Possible (int n, int k, int d) {
    int tmp = 1;
    for (int i = 0; i < d; i++) {
        tmp *= k;
        if (tmp >= n) return true;
    }
    return false;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    FAST

    int n, k, d;
    cin >> n >> k >> d;
    int N = n;

    if (!Possible(n, k, d)) cout << -1 << '\n';
    else {
        Backtrack(d, n, k);
        for (int i = 1; i <= d; i++) {
            for (int j = 1; j <= N; j++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }


    return 0;
}







