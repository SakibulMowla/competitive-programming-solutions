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

    int n;
    string s;
    cin >> n >> s;

    vector <char> rev(200);
    rev['U'] = 'D';
    rev['D'] = 'U';
    rev['L'] = 'R';
    rev['R'] = 'L';
    vector <int> isActive(200, 0);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (isActive[rev[s[i]]]) {
            ans++;
            isActive['R'] = 0;
            isActive['L'] = 0;
            isActive['U'] = 0;
            isActive['D'] = 0;
        }
        isActive[s[i]] = 1;
    }

    cout << ans + (int)(bool)(isActive['L'] + isActive['R'] + isActive['U'] + isActive['D']) << endl;

    return 0;
}





