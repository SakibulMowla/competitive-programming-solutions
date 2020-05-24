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
#define MP(a,b) make_pair(a,b)
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

#define SZ  1010

int best (int a, int b, int n) {
    if (abs(a-n) < abs(b-n)) return a;
    return b;
}

int lb (vector <int>&a, int x) {
    int ans = a[sz(a) - 1];
    int lo = 0;
    int hi = sz(a) - 1;
    while (lo <= hi) {
        int mid = (lo+hi) >> 1;
        if (a[mid] <= x) {
            lo = mid + 1;
            ans = best(ans, a[mid], x);
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

int hb (vector <int>&a, int x) {
    int ans = a[0];
    int lo = 0;
    int hi = sz(a) - 1;
    while (lo <= hi) {
        int mid = (lo+hi) >> 1;
        if (a[mid] >= x) {
            hi = mid - 1;
            ans = best(ans, a[mid], x);
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n;
    int test = 0;

    while (scanf("%d", &n) == 1) {
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        sort(a.begin(), a.end());

        int m;
        scanf("%d", &m);

        printf("Case %d:\n", ++test);
        for (int i = 0; i < m; i++) {
            int x;
            scanf("%d", &x);
            int ans = 1E9;
            for (int j = 0; j < n; j++){
                int tmp = a[j];
                a.erase(a.begin()+j);
                ans = best(ans, tmp + lb(a, x-tmp), x);
                ans = best(ans, tmp + hb(a, x-tmp), x);
                a.insert(a.begin()+j, tmp);
            }
            printf("Closest sum to %d is %d.\n", x, ans);
        }
    }

    return 0;
}





