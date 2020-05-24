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

typedef pair<ll , ll> pii;
const ll inf = 1;
const ll mod = 1LL;

#define SZ 50

typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;
typedef vector<pii> VP;
typedef vector<VP> VPP;

pii MinCostMatching(const VVD &cost, VI &Lmate, VI &Rmate, VPP &frac) {
    int n = int(cost.size());

    // construct dual feasible solution
    VD u(n);
    VD v(n);
    for (int i = 0; i < n; i++) {
        u[i] = cost[i][0];
        for (int j = 1; j < n; j++) u[i] = min(u[i], cost[i][j]);
    }
    for (int j = 0; j < n; j++) {
        v[j] = cost[0][j] - u[0];
        for (int i = 1; i < n; i++) v[j] = min(v[j], cost[i][j] - u[i]);
    }

    // construct primal solution satisfying complementary slackness
    Lmate = VI(n, -1);
    Rmate = VI(n, -1);
    int mated = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (Rmate[j] != -1) continue;
            if (fabs(cost[i][j] - u[i] - v[j]) < 1e-10) {
                Lmate[i] = j;
                Rmate[j] = i;
                mated++;
                break;
            }
        }
    }

    VD dist(n);
    VI dad(n);
    VI seen(n);

    // repeat until primal solution is feasible
    while (mated < n) {

        // find an unmatched left node
        int s = 0;
        while (Lmate[s] != -1) s++;

        // initialize Dijkstra
        fill(dad.begin(), dad.end(), -1);
        fill(seen.begin(), seen.end(), 0);
        for (int k = 0; k < n; k++)
            dist[k] = cost[s][k] - u[s] - v[k];

        int j = 0;
        while (true) {

            // find closest
            j = -1;
            for (int k = 0; k < n; k++) {
                if (seen[k]) continue;
                if (j == -1 || dist[k] < dist[j]) j = k;
            }
            seen[j] = 1;

            // termination condition
            if (Rmate[j] == -1) break;

            // relax neighbors
            const int i = Rmate[j];
            for (int k = 0; k < n; k++) {
                if (seen[k]) continue;
                const double new_dist = dist[j] + cost[i][k] - u[i] - v[k];
                if (dist[k] > new_dist) {
                    dist[k] = new_dist;
                    dad[k] = j;
                }
            }
        }

        // update dual variables
        for (int k = 0; k < n; k++) {
            if (k == j || !seen[k]) continue;
            const int i = Rmate[k];
            v[k] += dist[k] - dist[j];
            u[i] -= dist[k] - dist[j];
        }
        u[s] += dist[j];

        // augment along path
        while (dad[j] >= 0) {
            const int d = dad[j];
            Rmate[j] = Rmate[d];
            Lmate[Rmate[j]] = j;
            j = d;
        }
        Rmate[j] = s;
        Lmate[s] = j;

        mated++;
    }

    pii ans = MP(1LL, 1LL);

    for (int i = 0; i < n; i++) {
        ans.X *= frac[i][Lmate[i]].X;
        ans.Y *= frac[i][Lmate[i]].Y;

        ll g = __gcd(ans.X, ans.Y);

        ans.X /= g;
        ans.Y /= g;
    }

    ans.X = ans.Y - ans.X;

    ll g = __gcd(ans.X, ans.Y);

    ans.X /= g;
    ans.Y /= g;

    return ans;
}


int main() {
    #if defined JESI
    //        freopen("1.txt", "r", stdin);
    //        freopen("2.txt", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int n;
        scanf("%d", &n);

        VVD cost(n, VD(n, 0));
        VPP frac(n, VP(n));
        VI Lmate(n);
        VI Rmate(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%lld/%lld", &frac[i][j].X, &frac[i][j].Y);

                frac[i][j].X = frac[i][j].Y - frac[i][j].X;

                double d = (double)frac[i][j].X / (double)frac[i][j].Y;

                if (d + 1E-10 >= 0) cost[i][j] = -log(d);
            }
        }

        pii ans = MinCostMatching(cost, Lmate, Rmate, frac);

        printf("%lld/%lld\n", ans.X, ans.Y);
    }

    return 0;
}






