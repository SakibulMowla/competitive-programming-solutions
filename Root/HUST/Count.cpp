#include "bits/stdc++.h"

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

#define SZ  110

bool get(int *a) {
    char *p = (char*)a;
    int q;
    q = getchar(); if(q<0) return false; *(p++)=q;
    q = getchar(); if(q<0) return false; *(p++)=q;
    q = getchar(); if(q<0) return false; *(p++)=q;
    q = getchar(); if(q<0) return false; *(p++)=q;
    return true;
}

int a[10000][10000];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

//    ios::sync_with_stdio(0);

    int n, m;
//    cin >> n >> m;

    get(&n);
    get(&m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            get(&a[i][j]);
        }
    }

    int x, y;
    while (get(&x) && get(&y)) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += upper_bound(a[i], a[i]+m, y) - lower_bound(a[i], a[i]+m, x);
        }

        printf("%d\n", ans);
    }

    return 0;
}






