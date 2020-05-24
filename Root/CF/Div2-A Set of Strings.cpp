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


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int k;
    cin >> k;
    string s;
    cin >> s;

    vector <int> cnt(26, 0);

    int distinct = 0;
    for (int i = 0; i < sz(s); i++) {
        cnt[s[i]-'a']++;
        if (cnt[s[i]-'a'] == 1) {
            distinct++;
        }
    }

    if (distinct < k) {
        cout << "NO" << endl;
    } else {
        cout << "YES";
        fill(cnt.begin(), cnt.end(), 0);
        for (int i = 0; i < sz(s); i++) {
            cnt[s[i]-'a']++;
            if (cnt[s[i]-'a'] == 1 && k) {
                k--;
                cout << endl;
            }
            cout << s[i];
        }
    }


    return 0;
}







