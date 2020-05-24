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


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector <int> cnt(10000001, 0);

    vector <int> a(n1);
    for (int i = 0; i < n1; i++) {
        cin >> a[i];
    }
    for (int i = n1 - 1, sum = 0; i >= 0; i--) {
        sum += a[i];
        cnt[sum]++;
    }

    a.resize(n2);
    for (int i = 0; i < n2; i++) {
        cin >> a[i];
    }
    for (int i = n2 - 1, sum = 0; i >= 0; i--) {
        sum += a[i];
        cnt[sum]++;
    }

    a.resize(n3);
    for (int i = 0; i < n3; i++) {
        cin >> a[i];
    }
    for (int i = n3 - 1, sum = 0; i >= 0; i--) {
        sum += a[i];
        cnt[sum]++;
    }

    int ans = 0;
    for (int i = 1; i <= 100 * n1; i++) {
        if (cnt[i] == 3) {
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}


