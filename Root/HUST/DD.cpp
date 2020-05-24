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

void f (int a[], int n) {
    int m = n;
    while (m >= 2) {
        a[2] += m/2;
        m /= 2;
    }
    m = n;
    while (m >= 3) {
        a[3] += m/3;
        m /= 3;
    }
    m = n;
    while (m >= 5) {
        a[5] += m/5;
        m /= 5;
    }
    m = n;
    while (m >= 7) {
        a[7] += m/7;
        m /= 7;
    }
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

//    ios::sync_with_stdio(false);

    int a1[11], a2[11];
    int n, m;

    while (scanf("%d %d", &n, &m) == 2 && (n + m)) {
        mem(a1, 0);
        mem(a2, 0);
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            f(a1, x);
        }
        for (int i = 0; i < m; i++) {
            int x;
            scanf("%d", &x);
            f(a2, x);
        }
        if (a1[2] == a2[2] && a1[3] == a2[3] && a1[5] == a2[5] && a1[7] == a2[7]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }


    return 0;
}





