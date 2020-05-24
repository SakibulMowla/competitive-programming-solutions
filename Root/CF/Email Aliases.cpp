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

void disCapitalize (string &s) {
    for (auto &ch: s) {
        ch = tolower(ch);
    }
    return;
}

string bmail = "@bmail.com";

bool checkDomain (string &s) {
    int k = sz(bmail);
    if (k > sz(s)) return false;
    for (int i = 0, j = sz(s) - 1; i < k; i++, j--) {
        if (bmail[i] != s[j]) {
            return false;
        }
    }
    return true;
}

void cutAlias (string &s) {
//    cout << ">>> " << s << endl;
    bool flag = false;
    vector <bool> mark(sz(s), false);
    for (int i = 0; i < sz(s); i++) {
        if (!flag && s[i] == '+') {
            flag = true;
        }
        if (s[i] == '@') {
            break;
        }
        mark[i] = flag;
        if (s[i] == '.') {
            mark[i] = true;
        }
    }
    string tmp = "";
    for (int i = 0; i < sz(s); i++) {
        if (!mark[i]) {
            tmp += s[i];
        }
    }
    s = tmp;
//    cout << s << endl;
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <string> a(n), tmp(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tmp[i] = a[i];
        disCapitalize(tmp[i]);
    }

//    for (auto &s: tmp) {
//        cout << s << endl;
//    }

    reverse(bmail.begin(), bmail.end());

    map <string, int> mp;
    vector <vector <int>> ans;
    int cnt = 0, i = 0;

    for (auto &s: tmp) {
        if (checkDomain(s)) {
            cutAlias(s);
        }
//        cout << ">> " << s << endl;
        if (mp.find(s) == mp.end()) {
            mp[s] = cnt++;
            ans.pb(vector <int>());
            ans[cnt-1].pb(i);
        } else {
            ans[mp[s]].pb(i);
        }
        i++;
    }

    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        cout << sz(ans[i]);
        for (int j = 0; j < sz(ans[i]); j++) {
            cout << ' ' << a[ans[i][j]];
        }
        cout << endl;
    }

    return 0;
}


