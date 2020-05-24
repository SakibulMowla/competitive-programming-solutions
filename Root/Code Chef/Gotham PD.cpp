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
    struct Node {
        int child[2];
        int cnt;
        Node () {
            child[0] = child[1] = -1;
            cnt = 0;
        }
    };

    vector <Node> T;
    int nodes;

    Trie() {
        T.pb(Node());
        nodes = 0;
    }

    void Insert(int k) {
        int now = 0;
        T[now].cnt++;
        for (int i = 31; i >= 0; i--) {
            int bit = ((k >> i) & 1);
            if (T[now].child[bit] == -1) {
                T.pb(Node());
                T[now].child[bit] = ++nodes;
            }
            now = T[now].child[bit];
            T[now].cnt++;
        }
        return;
    }

    void Remove(int k) {
        int now = 0;
        T[now].cnt--;
        for (int i = 31; i >= 0; i--) {
            int bit = ((k >> i) & 1);
            now = T[now].child[bit];
            T[now].cnt--;
        }
        return;
    }

    int findMax(int k) {
        int now = 0, ans = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = ((k >> i) & 1);
            ans <<= 1;
            if (T[now].child[bit ^ 1] != -1 && T[T[now].child[bit ^ 1]].cnt > 0) {
                now = T[now].child[bit ^ 1];
                ans |= 1;
            } else {
                now = T[now].child[bit];
            }
        }
        return ans;
    }

    int findMin(int k) {
        int now = 0, ans = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = ((k >> i) & 1);
            ans <<= 1;
            if (T[now].child[bit] != -1 && T[T[now].child[bit]].cnt > 0) {
                now = T[now].child[bit];
            } else {
                now = T[now].child[bit ^ 1];
                ans |= 1;
            }
        }
        return ans;
    }
};

struct Graph {
    int n;
    int q;
    vector < vector <int> > G;
    unordered_map <int, int> mp;
    vector <int> key;
    vector <pii> ans;
    vector < vector <pii> > question;
    int nodes = 0;
    int root;
    char s[100];

    Graph(int n, int q): n(n), q(q), G(n + q, vector <int> ()), nodes(0), key(n + q), ans(q), question(n + q, vector <pii> ()) {
        scanf("%d %d", &root, &key[0]);
        if (mp.find(root) == mp.end()) mp[root] = nodes++;

        for (int i = 0; i < n - 1; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            if (mp.find(u) == mp.end()) mp[u] = nodes++;
            if (mp.find(v) == mp.end()) mp[v] = nodes++;
            u = mp[u], v = mp[v];
            key[u] = w;
            G[v].pb(u);
        }

        int queries = 0;

        for (int i = 0; i < q; i++) {
            scanf(" %[^\n]", s);
            int type, v, u, k;
            int cnt = sscanf(s, "%d %d %d %d", &type, &v, &u, &k);
            if (cnt == 3) {
                int last = type ^ 1;
                v ^= last, k = u ^ last;
                v = mp[v];
                question[v].pb({k, queries++});
            } else {
                int last = type;
                v ^= last, u ^= last, k ^= last;
                mp[u] = nodes++;
                u = mp[u], v = mp[v];
                key[u] = k;
                G[v].pb(u);
            }
        }

        solveLarge();

        for (int i = 0; i < queries; i++) {
            printf("%d %d\n", ans[i].X, ans[i].Y);
        }
    }

    void solveLarge() {
        Trie tree;
        traverse(0, tree);
    }

    void traverse(int u, Trie& tree) {
        tree.Insert(key[u]);
        for (auto &y: question[u]) ans[y.Y] = {tree.findMin(y.X), tree.findMax(y.X)};
        for (auto v: G[u]) traverse(v, tree);
        tree.Remove(key[u]);
        return;
    }
};

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    Graph Solve(n, q);

    return 0;
}
