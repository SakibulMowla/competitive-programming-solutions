//#include <bits/stdc++.h>

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
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <deque>
#include <assert.h>
#include <time.h>

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

int findCost(int a, int b, int n) {
    if (b < a) b += n;
    return b - a;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> cost(n, 1E9);
    vector<int> count(n, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cost[a - 1] = min(cost[a - 1], findCost(a - 1, b - 1, n));
        count[a - 1]++;
    }

    for (int i = 0; i < n; i++) {
        if (count[i]) {
            cost[i] = (count[i] - 1) * n + cost[i];
        } else {
            cost[i] = 0;
        }
    }

    for (int start = 0; start < n; start++) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (cost[i]) {
                ans = max(ans, findCost(start, i, n) + cost[i]);
            }
        }
        cout << ans << ' ';
    }
    cout << endl;

    return 0;
}





