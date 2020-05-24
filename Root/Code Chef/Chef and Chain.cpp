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

#define SZ 100010



int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    FAST

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        string s;
        cin >> s;
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < sz(s); i++) {
            if (i & 1) {
                if (s[i] != '+') ans1++;
                if (s[i] != '-') ans2++;
            } else {
                if (s[i] != '+') ans2++;
                if (s[i] != '-') ans1++;
            }
        }
        cout << min(ans1, ans2) << '\n';
    }


    return 0;
}




