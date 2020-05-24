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


#define SZ 100010

int now;
int col[64][2][2][1025];
ll dp[64][2][2][1025]; //pos, flag, base, mask
ll store[11][64][2][2][1025];
int arr[64];
int len;
ll base;

void prepare(ll n) {
    len = 0;
    while (n) {
        arr[len++] = n % base;
        n /= base;
    }
    return;
}

ll solve(int pos, bool strt, int flag, int mask) {
    if (pos == -1) return (mask == 0 && strt);
    
    if (flag == 0 && store[base][pos][strt][flag][mask] != -1) return store[base][pos][strt][flag][mask];

    ll& ret = dp[pos][strt][flag][mask];
    if (col[pos][strt][flag][mask] == now) return ret;
    col[pos][strt][flag][mask] = now;
    
    ret = 0;
    int lim = (flag ? arr[pos]: base - 1);
    
    for (int i = 0; i <= lim; i++) {
        int nmask = mask;
        if ((i == 0 && strt) || (i > 0)) {
            nmask ^= (1 << i);
        } 
        ret += solve(pos - 1, strt || (bool)(i != 0), (i == lim ? flag : 0), nmask);
    }

    return store[base][pos][strt][flag][mask] = ret;
}

ll solve(ll n) {
    if (n == 0) return 0;
    //mem(dp, -1);
    ++now;
    prepare(n);
    return solve(len - 1, 0, 1, 0);
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    mem(store, -1);

    int q;
    cin >> q;

    while (q--) {
        ll l, r;
        cin >> base >> l >> r;
        cout << solve(r) - solve(l - 1) << endl;
    }

    return 0;
}


