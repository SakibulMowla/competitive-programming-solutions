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

int fun (int &x, int &y) {
    int ans = 0;
    for (int i = 0; i < 15; i++) {
        if (i & 1) ans ^= x & ~y;
        else ans ^= y & ~x;
        swap(x, y);
    }
    return ans;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

//    ios::sync_with_stdio(false);

    clock_t t = clock();

    int x = rand(), y = rand(), ans;

    for (int i = 0; i < 352; i++) {
        for (int j = 0; j < 288; j++) {
            x ^= y;
            ans += fun(x, y);
        }
        y &= ~x;
    }

    t = clock() - t;

    printf("Time Lapse = %.15f\n", (float)t / CLOCKS_PER_SEC);

    return 0;
}





