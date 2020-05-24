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



int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    srand(time(NULL));

    int n, start, x;
    scanf("%d %d %d", &n, &start, &x);

//    printf("! %d", rand());
//    return 0;

    vector<int> a(n);
    for (int i = 1; i <= n; i++) {
        a[i - 1] = i;
    }

    printf("? %d\n", start);
    fflush(stdout);

    int v, vx;
    scanf("%d %d", &v, &vx);

    int ans = 2E9, remaining = 1998 - min(n, 1298);
    for (int i = 1; i <= min(n, 1298); i++) {
        random_shuffle(a.begin(), a.end());
        int index = a[0];
        a.erase(a.begin());
        printf("? %d\n", index);
        fflush(stdout);
        int value, next;
        scanf("%d %d", &value, &next);
        if (value < x) {
            if (value > v) {
                v = value;
                vx = next;
            }
        } else {
            ans = min(ans, value);
        }
    }

    for (int i = 1; i <= remaining && vx != -1; i++) {
        if (v < x) {
            printf("? %d\n", vx);
            fflush(stdout);
            scanf("%d %d", &v, &vx);
        }
    }

    if (v >= x) ans = min(ans, v);
    if (ans == 2E9) ans = -1;

    printf("! %d\n", ans);
    fflush(stdout);

    return 0;
}




