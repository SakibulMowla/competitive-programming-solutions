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

struct trie {
    int cnt, dir[2];
    trie() {
        cnt = 0;
        dir[0] = dir[1] = -1;
    }
};

vector <trie> T;
int sz;

void insert (int n) {
    int now = 0;
    for (int i = 16; i >= 0; i--) {
        if (T[now].dir[bool(n&(1<<i))] == -1) {
            T.pb(trie());
            now = T[now].dir[bool(n&(1<<i))] = sz++;
        } else {
            now = T[now].dir[bool(n&(1<<i))];
        }
    }
    T[now].cnt++;
    return;
}

void outsert (int n) {
    int now = 0;
    for (int i = 16; i >= 0; i--) {
        if (T[now].dir[bool(n&(1<<i))] == -1) {
            T.pb(trie());
            now = T[now].dir[bool(n&(1<<i))] = sz++;
        } else {
            now = T[now].dir[bool(n&(1<<i))];
        }
    }
    T[now].cnt--;
    return;
}

int solve (int now, int bit, int n) {
    if (bit == -1) {
        return T[now].cnt;
    }
    int ret = 0;
    if (T[now].dir[0] != -1) ret = solve(T[now].dir[0], bit - 1, n);
    if ((n & (1<<bit)) && T[now].dir[1] != -1) ret += solve(T[now].dir[1], bit - 1, n);
    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int q;
    scanf("%d", &q);

    T.pb(trie());
    sz = 1;

    char s[4];
    int n;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", s, &n);
        if (s[0] == 'a') {
            insert(n);
        } else if (s[0] == 'd') {
            outsert(n);
        } else {
            printf("%d\n", solve(0, 16, n));
        }
    }

    return 0;
}







