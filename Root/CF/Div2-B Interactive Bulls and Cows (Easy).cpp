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

    ios::sync_with_stdio(false);

    string v = "";

    for (int i = 0, b, c; i < 10; i++) {
        printf("%d%d%d%d\n", i, i, i, i);
        fflush(stdout);
        scanf("%d %d", &b, &c);
        if (b) {
            v += (char)('0' + i);
        }
    }

    do {
        printf("%s\n", v.c_str());
        fflush(stdout);
        int b, c;
        scanf("%d %d", &b, &c);
        if (b == 4 && c == 0) {
            break;
        }
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}





