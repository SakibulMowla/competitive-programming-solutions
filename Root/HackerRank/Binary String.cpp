#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  100010

char s[SZ];
vector <int> pos[SZ];
int l[SZ];
int r[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, k, t;
    scanf("%d %d %d", &n, &k, &t);
    scanf("%s", s + 1);

    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            pos[i%k].pb(i);
            r[i%k]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            printf("1");
            int now = (i % k);
            if (l[now] != r[now]) {
                if (pos[now][l[now]] <= i) {
                    l[now]++;
                }
            }
        } else {
            int now = (i % k);
            if (l[now] != r[now] && (t - ((pos[now][l[now]] - i) / k)) >= 0) {
                s[pos[now][l[now]]] = '0';
                t -= (pos[now][l[now]] - i) / k;
                l[now]++;
                printf("1");
            } else {
                printf("0");
            }
            if (l[now] != r[now]) {
                if (pos[now][l[now]] <= i) {
                    l[now]++;
                }
            }
        }
    }
    printf("\n");

    return 0;
}


