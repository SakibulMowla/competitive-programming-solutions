#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>
#include <assert.h>
#include <time.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1LL;

#define SZ  10010

char pat[SZ], txt[SZ];
int par[SZ];

void pre_process () {
    int n = strlen(pat);
    int k = 0;
    par[0] = 0;

    for (int i = 1; i < n; i++) {
        while (k && pat[i] != pat[k])
            k = par[k-1];
        if (pat[i] == pat[k])
            k++;
        par[i] = k;
    }

    return;
}

int dp[10010][1010];
int col[10010][1010];
int now;
int tlen, plen;

int nxt[1010][27];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    while (gets(txt)) {
        gets(pat);

        tlen = strlen(txt);
        plen = strlen(pat);

        pre_process();

        for (int pos = 0; pos <= tlen; pos++) {
            for (int match = 0; match <= plen; match++) {
                dp[pos][match] = 1E7;
            }
        }

        dp[0][0] = 0;
        int mx = 0;

        for (int i = 0; i < plen; i++) {
            for (char j = 'a'; j <= 'z'; j++) {
                int tmp = i;
                while (tmp && pat[tmp] != j)
                    tmp = par[tmp-1];
                if (pat[tmp] == j)
                    tmp++;
                nxt[i][j-'a'] = tmp;
            }
        }


        for (int pos = 0; pos < tlen; pos++) {
            for (int match = 0; match < plen; match++) if (dp[pos][match] != 1E7) {
                dp[pos+1][match] = min(dp[pos+1][match], 1 + dp[pos][match]);

                int tmp = nxt[match][txt[pos]-'a'];
                if (tmp == plen) dp[pos+1][tmp] = min(dp[pos+1][tmp], (int)1E7);
                else dp[pos+1][tmp] = min(dp[pos+1][tmp], dp[pos][match]);
                mx = max(mx, tmp);
            }
        }

        int ans = 1E7;
        for (int i = 0; i < plen; i++) {
            ans = min(ans, dp[tlen][i]);
        }

        printf("%d\n", ans);
    }

    return 0;
}



