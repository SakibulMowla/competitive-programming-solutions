#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1LL;

#define SZ  100010



int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        string s;
        cin >> s;
        vector <int> cnt(26, 0);
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i]-'a']++;
        }
        string ans = "";
        int pre = -1;
        for (int i = 0; i < s.size(); i++) {
            int best = 0, indx;
            for (int j = 0; j < 26; j++) if (j != pre) {
                if (cnt[j] > best) {
                    best = cnt[j];
                    indx = j;
                }
            }
            if (best == 0) {
                ans = "-1";
                goto HELL;
            }
            ans += (char)indx + 'a';
            cnt[indx]--;
            pre = indx;
        }
        HELL:;
        cout << ans << endl;
    }

    return 0;
}




