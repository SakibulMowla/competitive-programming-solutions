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


#define SZ 701

int n;
vector<int> a;
int dp[SZ][SZ][2];

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int solve(int l, int r, int par, int dir) {
    if (l > r) return 1;
    if (l == r) return gcd(par, a[l]) > 1;
    if (dp[l][r][dir] != -1) return dp[l][r][dir];
    dp[l][r][dir] = 0;
    for (int i = l; i <= r; i++) {
        if (gcd(par, a[i]) > 1 && solve(l, i - 1, a[i], 0) == 1 && solve(i + 1, r, a[i], 1) == 1) {
            dp[l][r][dir] = 1;
            break;
        }
    }
    return dp[l][r][dir];
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    cin >> n;
    a = vector<int> (n);
    for (auto& x: a) cin >> x;

    memset(dp, -1, sizeof dp);
    cout << (solve(0, n - 1, 0, 0) == 1 ? "Yes" : "No") << endl;

    return 0;
}




