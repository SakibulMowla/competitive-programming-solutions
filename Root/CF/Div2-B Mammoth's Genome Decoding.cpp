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
    ios::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;

    if (n % 4 != 0) {
        cout << "===" << endl;
    } else {
        vector <int> cnt(200, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') continue;
            cnt[s[i]]++;
            if (cnt[s[i]] > n / 4) {
                cout << "===" << endl;
                return 0;
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                if (cnt['A'] < (n / 4)) s[i] = 'A';
                else if (cnt['C'] < (n / 4)) s[i] = 'C';
                else if (cnt['G'] < (n / 4)) s[i] = 'G';
                else if (cnt['T'] < (n / 4)) s[i] = 'T';
                cnt[s[i]]++;
            }
        }
        cout << s << endl;
    }

    return 0;
}





