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

struct Trie {
    int child[2], cnt;
    Trie () {
        child[0] = child[1] = -1;
        cnt = 0;
    }
};

vector <Trie> T;
int nodes = 0;

void add (int num) {
    int now = 0;
    for (int i = 31; i >= 0; i--) {
        int bit = ((num >> i) & 1);
        if (T[now].child[bit] == -1) {
            T[now].child[bit] = nodes++;
            T.pb(Trie());
        }
        now = T[now].child[bit];
        T[now].cnt++;
    }
    return;
}

void Remove (int num) {
    int now = 0;
    for (int i = 31; i >= 0; i--) {
        int bit = ((num >> i) & 1);
        now = T[now].child[bit];
        T[now].cnt--;
    }
    return;
}

ll FindAns (ll x) {
    int now = 0;
    ll ans = 0;
    for (int i = 31; i >= 0; i--) {
        int bit = !((x >> i) & 1);
        ans <<= 1;
        if (T[now].child[bit] != -1 && T[T[now].child[bit]].cnt > 0) {
            now = T[now].child[bit];
            ans |= 1;
        } else {
            now = T[now].child[!bit];
        }
    }
    return ans;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    T.pb(Trie());
    nodes = 1;
    add(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char ch;
        ll x;
        cin >> ch >> x;
        if (ch == '+') add(x);
        else if (ch == '-') Remove(x);
        else cout << FindAns(x) << endl;
    }

    return 0;
}





