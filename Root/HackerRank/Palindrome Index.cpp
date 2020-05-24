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

bool isPalindrome (string& s) {
    int n = sz(s);
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
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

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        string s;
        cin >> s;
        int n = sz(s);
        if (isPalindrome(s)) {
            cout << - 1 << endl;
        } else {
            int l = 0, r = n - 1;
            while (l < r) {
                if (s[l] != s[r]) {
                    string L = s; L.erase(l, 1);
                    string R = s; R.erase(r, 1);
                    if (isPalindrome(L)) cout << l << endl;
                    else if (isPalindrome(R)) cout << r << endl;
                    else cout << -1 << endl;
                    break;
                }
                l++, r--;
            }
        }
    }

    return 0;
}





