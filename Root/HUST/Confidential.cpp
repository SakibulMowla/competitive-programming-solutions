#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>
#include <assert.h>
#include <time.h>

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  510

struct data {
    int u, v, w, idx;
};

bool comp (data a, data b) {
    return a.w < b.w;
}

int par[SZ];

int Find (int r) {
    if (r == par[r]) return r;
    return par[r] = Find(par[r]);
}

int ans1, ans2;

void init (int n) {
    for (int i = 0; i <= n; i++) {
        par[i] = i;
    }
    return;
}

void solve (int n, int m, vector <data> &edge) {
    sort(edge.begin(), edge.end(), comp);
    init(n);
    int cnt = 0, tmp = 0;
    vector <int> v;
    for (int i = 0; i < m; i++) {
        int x = Find(edge[i].u);
        int y = Find(edge[i].v);
        if (x != y) {
            par[x] = y;
            cnt++;
            tmp += edge[i].w;
            v.pb(edge[i].idx);
            if (cnt == n-1) {
                ans1 = tmp;
                break;
            }
        }
    }
    if (cnt != n-1) return;

//    cout << "Here\n";
//    cout << "sz = " << sz(v) << endl;

    for (int j = 0; j < sz(v); j++) {
//        cout << "j = " << j << endl;
        cnt = 0;
        tmp = 0;
        init(n);
        for (int i = 0; i < m; i++) {
            if (edge[i].idx == v[j]) continue;
            int x = Find(edge[i].u);
            int y = Find(edge[i].v);
            if (x != y) {
                par[x] = y;
                cnt++;
                tmp += edge[i].w;
                if (cnt == n-1) {
                    break;
                }
            }
        }
        if (cnt == n-1) {
            ans2 = min(ans2, tmp);
        }
    }

    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n, m;
//    while () {
        cin >> n >> m;
        vector <data> edge(m);
        for (int i = 0; i < m; i++) {
            cin >> edge[i].u >> edge[i].v >> edge[i].w;
            edge[i].idx = i;
        }

        ans1 = ans2 = inf;
        solve(n, m, edge);

        cout << "Cost: " << (ans1 == inf? -1: ans1) << endl;
        cout << "Cost: " << (ans2 == inf? -1: ans2) << endl;
//    }

    return 0;
}



