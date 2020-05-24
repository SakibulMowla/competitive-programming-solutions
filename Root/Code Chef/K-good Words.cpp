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

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        string s;
        int k;
        cin >> s >> k;

        vector <int> cnt(26, 0);
        for (auto x: s) {
            cnt[x-'a']++;
        }

        int ans = numeric_limits <int> :: max(), n = sz(s);

        for (int i = 0; i <= n; i++) {
            int tmp = 0;
            for (int j = 0; j < 26; j++) {
                if (cnt[j] < i) tmp += cnt[j];
                if (cnt[j] > i + k) tmp += (cnt[j] - (i + k));
            }
            ans = min(ans, tmp);
        }

        cout << ans << endl;
    }


    return 0;
}





