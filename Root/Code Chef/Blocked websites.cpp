#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;

const int inf = 1E9;
const ll mod = 1LL;

#define SZ  110

struct Trie {
    int val[2]; // 0->good 1-> bad
    map <char, int> mp;
    Trie () {
        val[0] = val[1] = 0;
    }
};

vector <Trie> T;
int nodes;
vector <string> ans;
string tmp;

void Insert (string &s, int indx) {
    int now = 0;
    T[now].val[indx]++;
    for (auto x: s) {
        if (T[now].mp.find(x) == T[now].mp.end()) {
            T[now].mp[x] = ++nodes;
            T.push_back(Trie());
        }
        now = T[now].mp[x];
        T[now].val[indx]++;
    }
    return;
}

bool flag;

void solve (int now) {
    if (flag == false) return;
    if (T[now].val[0] == 0 && now != 0) {
        ans.push_back(tmp);
        return;
    } else if (T[now].val[1] == 0) {
        return;
    }
    int bad = 0;
    for (auto x: T[now].mp) {
        bad += T[x.Y].val[1];
    }
    if (bad != T[now].val[1]) {
        flag = false;
        return;
    }
    for (auto x: T[now].mp) {
        tmp.push_back(x.X);
        solve(x.Y);
        tmp.pop_back();
    }
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    T.push_back(Trie());
    nodes = 0;

    for (int i = 0; i < n; i++) {
        char ch;
        string s;
        cin >> ch >> s;
        Insert(s, ch == '+' ? 0 : 1);
    }

    tmp = "";
    flag = true;

    solve(0);

    if (flag == false) {
        cout << -1 << endl;
    } else {
        cout << sz(ans) << endl;
        for (auto x: ans) {
            cout << x << endl;
        }
    }

    return 0;
}


