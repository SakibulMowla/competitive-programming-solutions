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

char mp[400][400];

bool isVowel (char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int solve (string &word, int player) {
    int ret;
    if (sz(word) == 1) {
        ret = isVowel(word[0]);
    } else {
        string a = "";
        for (int i = 0; i < sz(word); i += 2) {
            if (i + 1 < sz(word)) {
                a = a + mp[word[i]][word[i+1]];
            } else {
                a = a + word[i];
            }
        }
        int ret1 = solve(a, player ^ 1);

        a = "";
        for (int i = sz(word) - 1; i >= 0; i -= 2) {
            if (i - 1 >= 0) {
                a = mp[word[i]][word[i-1]] + a;
            } else {
                a = word[i] + a;
            }
        }

        int ret2 = solve(a, player ^ 1);

        if (player == 1) ret = max(ret1, ret2);
        else ret = min(ret1, ret2);
    }
    return ret;
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
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                cin >> mp[i+'a'][j+'a'];
            }
        }

        string s;
        cin >> s;

        cout << (solve(s, 1) == 1 ? "Salah" : "Marzo") << endl;
    }


    return 0;
}

