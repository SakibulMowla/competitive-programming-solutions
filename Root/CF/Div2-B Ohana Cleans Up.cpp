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

struct Data {
    int cnt;
    int dir[2];
    Data () {
        cnt = 0;
        mem(dir, -1);
    }
};

struct Trie {
    int n;
    int ans;
    int node;
    vector <Data> T;

    Trie (int _n) {
        n = _n;
        ans = 0;
        node = 0;
        T.clear();
        T.pb(Data());
    }

    void Insert (string &s) {
        int now = 0;
        for (int i = 0; i < n; i++) {
            if (T[now].dir[s[i]-'0'] == -1) {
                T.pb(Data());
                node++;
                now = T[now].dir[s[i]-'0'] = node;
            } else {
                now = T[now].dir[s[i]-'0'];
            }
            T[now].cnt++;
        }
        ans = max(ans, T[now].cnt);
    }
};

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    Trie Solve(n);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        Solve.Insert(s);
    }

    cout << Solve.ans << endl;


    return 0;
}







