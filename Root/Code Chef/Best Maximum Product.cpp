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
const ll mod = 1E9 + 7;


#define SZ 100010


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int n, k;
        scanf("%d %d", &n, &k);

        vector <int> pos, neg;
        ll ans = 1;

        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);

            if (x > 0) pos.push_back(x);
            else if (x < 0) neg.push_back(-x);

            ans = (ans * (ll)x) % mod;
            if (ans < 0) ans += mod;
        }

        sort(pos.rbegin(), pos.rend());
        sort(neg.rbegin(), neg.rend());

        int kept;
        int szp = sz(pos), szn = sz(neg);
        bool flag = false;

        if (szn % 2) {
            kept = -neg[szn-1];
            neg.pop_back();
            flag = true;
        }

        if (k <= szp + szn) {
            vector <double> lgpos(szp + 1, 0), lgneg(szn + 1, 0);

            for (int i = 1; i <= szp; i++) {
                lgpos[i] = lgpos[i-1] + log(pos[i-1]);
            }

            for (int i = 1; i <= szn; i++) {
                lgneg[i] = lgneg[i-1] + log(neg[i-1]);
            }

            double best = -1.0;
            int cntp = 0, cntn = 0;

            for (int i = 0; i <= min(szn, k); i += 2) {
                if (szp >= k - i) {
                    if (lgpos[k - i] + lgneg[i] > best) {
                        best = lgpos[k - i] + lgneg[i];
                        cntp = k - i;
                        cntn = i;
                    }
                }
            }

            ans = 1;

            for (int i = 0; i < cntp; i++) {
                ans = (ans * (ll)pos[i]) % mod;
            }

            for (int i = 0; i < cntn; i++) {
                ans = (ans * (ll)neg[i]) % mod;
            }

            if (!cntn && !cntp) {
                if (flag) {
                    k--;
                    ans = kept % mod;
                    if (ans < 0) ans += mod;
                }

                cout << ans << endl;

                for (int i = szn - 1; i >= 0 && k; i--, k--) {
                    ans = (ans * (ll)-neg[i]) % mod;
                    if (ans < 0) ans += mod;
                }

                for (int i = szp - 1; i >= 0 && k; i--, k--) {
                    ans = (ans * (ll)pos[i]) % mod;
                    if (ans < 0) ans += mod;
                }
            }
        }

        printf("%lld\n", ans);
    }


    return 0;
}


