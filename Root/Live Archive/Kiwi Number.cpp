#include <bits/stdc++.h>

using namespace  std;

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

#define SZ  34000

bool arr[SZ];

void sieve() {
    int k = sqrt(SZ);
    arr[0] = arr[1] = 1;
    for (register int i = 4; i < SZ; i += 2)
        arr[i] = 1;
    for (register int i = 3; i < SZ; i += 2)
        if (!arr[i])
            for (register int j = i * i; j < SZ; j += i + i)
                arr[j] = 1;
    return;
}


int divsr[200000+10];


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    sieve();

    int t;
    scanf("%d", &t);

    for (register int cs = 0; cs < t; cs++) {
        int a, b;
        scanf("%d %d", &a, &b);

        memset(divsr, 0, sizeof(int) * (b-a+5));

        int sq = sqrt(b);
        for (register int i = 1; i <= sq; i++) {
            int i2 = i * i;
            register int j = (a/i) * i;
            if (j < a) j += i;
            for (; j <= b; j += i) {
                if (j < i2) continue;
                if (j == i2) divsr[j-a]++;
                else divsr[j-a] += 2;
            }
        }

        int ans = 0;
        for (register int i = a; i <= b; i++) {
            if (!arr[ divsr[i-a] ]) {
                ans++;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}


