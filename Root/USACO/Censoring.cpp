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

#define SZ  10010
#define SZ1 1000010

char pat[SZ], txt[SZ1];
int par[SZ];

void pre_process() {
    int i, k, n;

    n = strlen(pat);
    k = 0;
    par[0] = 0;

    for(i=1; i<n; i++) {
        while(k>0 && pat[i] != pat[k])
            k = par[k-1];
        if(pat[i] == pat[k])
            k++;
        par[i] = k;
    }

    return ;
}

bool f[SZ1];
int tmp[SZ1];

void KMP_search() {
    int i, k, n, len, ans;

    n = strlen(txt);
    len = strlen(pat);
    ans = 0;
    k = 0;

    stack <int> ms;

    for(i=0; i<n; i++) {
        ms.push(i);
        while(k > 0 && txt[i] != pat[k])
            k = par[k-1];
        if(txt[i] == pat[k])
            k++;
        tmp[i] = k;
        if(k == len) {
            for (int j = 0; j < len; j++) {
                f[ms.top()] = 1;
                ms.pop();
            }
            if (ms.empty()) {
                k = 0;
            } else {
                k = tmp[ms.top()];
            }
        }
    }
    return;
}


int main() {
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);

    scanf("%s", txt);
    scanf("%s", pat);

    pre_process();
    KMP_search();

    int n = strlen(txt);
    for (int i = 0; i < n; i++) {
        if (!f[i]) {
            printf("%c", txt[i]);
        }
    }
    puts("");

    return 0;
}







