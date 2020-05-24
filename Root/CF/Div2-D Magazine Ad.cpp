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


#define SZ 1000010

char s[SZ];

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int k;
    scanf("%d %[^\n]", &k, s);

    int n = strlen(s);

    vector <int> closestLest(n + 2, 0);

    int pre = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == ' ' || s[i] == '-') pre = i + 1;
        closestLest[i + 1] = pre;
    }
    closestLest[n] = n;

    int lo = 1, hi = n, ans;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;

        bool flag = false;
        int pre = 0;
        for (int i = 0; i < k; i++) {
            int now = closestLest[min(pre + mid, n)];
            if (now <= pre) break;
            if (now == n) {
                flag = true;
                break;
            }
            pre = now;
        }

        if (flag) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}





