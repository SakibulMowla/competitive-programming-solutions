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


#define SZ 4000010

int sum[SZ];
int x[SZ], xsz;
int v2r[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

//    ios::sync_with_stdio(false);

    int n, k;
    vector <pii> segs, ans;

    while (scanf("%d %d", &n, &k) == 2) {
        for (int i = 0; i < n; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            segs.pb({2 * a, 2 * b});
            x[xsz++] = 2 * a;
            x[xsz++] = 2 * a - 1;
            x[xsz++] = 2 * b;
            x[xsz++] = 2 * b + 1;
        }

        sort(x, x + xsz);
        xsz = unique(x, x + xsz) - x;

        for (int i = 0; i < n; i++) {
            int a = lower_bound(x, x + xsz, segs[i].X) - x;
            int b = lower_bound(x, x + xsz, segs[i].Y) - x;
            v2r[a] = segs[i].X / 2;
            v2r[b] = segs[i].Y / 2;
            segs[i].X = a;
            segs[i].Y = b;
        }

        for (int i = 0; i < n; i++) {
            sum[segs[i].X]++;
            sum[segs[i].Y + 1]--;
        }

        for (int i = 1; i < xsz; i++) {
            sum[i] += sum[i-1];
        }

        for (int i = 0; i < xsz; i++) {
            if (sum[i] >= k) {
                int j = i;
                while (j + 1 < xsz && sum[j+1] >= k) {
                    j++;
                }
                ans.pb({v2r[i], v2r[j]});
                i = j;
            }
        }

        printf("%d\n", sz(ans));
        for (auto it: ans) {
            printf("%d %d\n", it.X, it.Y);
        }
    }


    return 0;
}





