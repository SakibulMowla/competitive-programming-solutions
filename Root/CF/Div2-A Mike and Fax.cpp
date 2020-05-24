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

bool check (string s) {
    int n = sz(s);
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n-i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    int k;
    cin >> k;

    int n = sz(s);
    if (n % k != 0) {
        cout << "NO" << endl;
    } else {
        bool flag = true;
        for (int i = 0; i < k; i++) {
            if (check(s.substr(0, n/k)) == false) {
                flag = false;
                break;
            }
            s.erase(0, n/k);
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}






