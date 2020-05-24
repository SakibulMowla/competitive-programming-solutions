#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 255

int a[SZ][SZ];
int l[SZ];
int r[SZ];
bool flag[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            a[i][j] += a[i-1][j];
        }
    }

    int mn, mx;
    scanf("%d %d", &mn, &mx);

    int ans = 0;

    for (int r1 = 1; r1 <= n; r1++) {
        for (int r2 = r1; r2 <= n; r2++) {

            int j = 1;
            int now = 0;
            mem(flag, 0);

            for (int i = 1; i <= m; i++) {
                l[i] = -1;
                if (now < mn) {
                    for (; j <= m; j++) {
                        now += a[r2][j] - a[r1-1][j];
                        flag[j] = true;
                        if (now >= mn) {
                            l[i] = j;
                            j++;
                            break;
                        }
                    }
                } else {
                    l[i] = max(i, j - 1);
                }
                if (flag[i]) {
                    now = now - (a[r2][i] - a[r1-1][i]);
                }
            }

            j = 1;
            now = 0;
            mem(flag, 0);

            for (int i = 1; i <= m; i++) {
                r[i] = -1;
                for (; j <= m; j++) {
                    if (now + a[r2][j] - a[r1-1][j] > mx) {
                        r[i] = j - 1;
                        break;
                    }
                    now += a[r2][j] - a[r1-1][j];
                    flag[j] = 1;
                    r[i] = j;
                }
                if (flag[i]) now -= a[r2][i] - a[r1-1][i];
            }

            printf("r1 = %d r2 = %d\n", r1, r2);
            for (int i = 1; i <= m; i++) {
                printf("i = %d l = %d r = %d\n", i, l[i], r[i]);
                if (l[i] != -1 && r[i] != -1 && l[i] <= r[i]){
                    ans += r[i] - l[i] + 1;
                }
            }
        }
    }

    printf("%d\n", ans);


    return 0;
}






