#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  100010

int Inversions (int n, vector <int> &a) {
    int inv = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] < a[j]) {
                inv++;
            }
        }
    }
    return inv;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <int> a(n);

    for (int &x: a) {
        cin >> x;
    }

    int ans = Inversions(n, a);
    int best = ans, x, y;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(a[i], a[j]);
            int tmp = Inversions(n, a);
            if (tmp < best) {
                best = tmp;
                x = i;
                y = j;
            }
            swap(a[i], a[j]);
        }
    }

    if (ans == best) cout << "Cool Array" << endl;
    else cout << x + 1 << ' ' << y + 1 << endl;

    return 0;
}



