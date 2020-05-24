#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;
using pll = pair <ll , ll>;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 10

map <ll, ll> forW[10], bckW[10];
ll finish[10];

int n, m;
ll arr[SZ];

struct data {
    int k;
    ll l, r;
};

data Q[1010];
int a[10];
bool mark;

ll solve () {
    ll sum = 0;
    ll ans = 0;
    int now = 0;

    for (int i = 0; i < m; i++) {
        int k = a[now];
        ll l = Q[i].l, r = Q[i].r;

        if (Q[i].k == a[now] && finish[k] + 1 == l) {
            finish[k] = r;
            if (forW[k][r+1]) {
                finish[k] = forW[k][r+1];
                sum -= forW[k][r+1] - r;
                bckW[k][ forW[k][r+1] ] = 0;
                forW[k][r+1] = 0;
            }
            if (finish[k] == arr[a[now]]) {
                now++;
                while (now < n && forW[ a[now] ][1]) {
                    finish[ a[now] ] = forW[ a[now] ][1];
                    sum -= forW[ a[now] ][1];
                    bckW[ a[now] ][ forW[ a[now] ][1] ] = 0;
                    forW[ a[now] ][1] = 0;
                    if (finish[ a[now] ] == arr[ a[now] ]) {
                        now++;
                    } else {
                        break;
                    }
                }
            }
        } else {
            k = Q[i].k;
            sum += r - l + 1LL;

            forW[k][l] = r;
            bckW[k][r] = l;

            if (bckW[k][l-1]) {
                bckW[k][r] = bckW[k][l-1];
                forW[k][ bckW[k][l-1] ] = r;
                forW[k][l] = 0;
                bckW[k][l-1] = 0;
            }
            if (forW[k][r+1]) {
                forW[k][ bckW[k][r] ] = forW[k][r+1];
                bckW[k][ forW[k][r+1] ] = bckW[k][r];
                forW[k][r+1] = 0;
                bckW[k][r] = 0;
            }
        }

        ans = max(ans, sum);
    }

    return ans;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("2.txt", "w", stdout);
    #endif

    FAST

    int Test = 0;

    while (cin >> n >> m && (n+m)) {
        for (int i = 0; i <= n; i++) {
            finish[i] = 0;
            clr(forW[i]);
            clr(bckW[i]);
            a[i] = i + 1;
        }

        for (int i = 0; i < n; i++) {
            cin >> arr[i+1];
        }

        for (int i = 0; i < m; i++) {
            cin >> Q[i].k >> Q[i].l >> Q[i].r;
        }

        ll ans = 1E18;

        do {
            for (int i = 0; i <= n; i++) {
                finish[i] = 0;
                clr(forW[i]);
                clr(bckW[i]);
            }
            ans = min(ans, solve());
        } while (next_permutation(a, a+n));

        cout << "Case " << ++Test << ": " << ans << "\n\n";
    }


    return 0;
}






