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


int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>());
    for (int i = 0; i < 2 * n; i++) {
        int x;
        cin >> x;
        cake[x - 1].push_back(i);
    }

    ll ans = 0;
    int posA = 0, posB = 0;

    for (int i = 0; i < n; i++) {
        ll costA = abs(posA - cake[i][0]) + abs(posB - cake[i][1]);
        ll costB = abs(posA - cake[i][1]) + abs(posB - cake[i][0]);
        if (costA <= costB) {
            posA = cake[i][0];
            posB = cake[i][1];
        } else {
            posB = cake[i][0];
            posA = cake[i][1];
        }
        ans += min(costA, costB);
    }

    cout << ans << endl;

    return 0;
}





