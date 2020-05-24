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

#define SZ 100010

char pat[SZ], txt[SZ], arr[SZ];
int par[SZ];

void pre_process() {
    int n = strlen(pat);
    int k = 0;
    par[0] = 0;

    for(int i = 1; i < n; i++) {
        while(k > 0 && pat[i] != pat[k])
            k = par[k-1];
        if(pat[i] == pat[k])
            k++;
        par[i] = k;
    }

    return ;
}

int KMP_search(int strt, int n) {
    pre_process();

    int len = strlen(pat);
    int ans = 0;
    int k = 0;

    for(int i = strt; i < n; i++) {
        while(k > 0 && txt[i] != pat[k])
            k = par[k-1];
        if(txt[i] == pat[k])
            k++;
        if(k == len) {
            return i - len + 1;
        }
    }

    return -1;
}

int main() {
#if defined JESI
//        freopen("bubble.in", "r", stdin);
//        freopen("bubble.out", "w", stdout);
#endif

    scanf(" %[^\n]", txt);
    scanf(" %[^\n]", arr);

    vector <bool> valid(strlen(txt), false);

    bool flag = true;
    char *s = strtok(arr, " ");
    int strt = 0;
    int n = strlen(txt);

    while (s != NULL) {
        strcpy(pat, s);
        int from = KMP_search(strt, n);
        if (from == -1) {
            flag = false;
            break;
        }
        int len = strlen(s);
        for (int i = from; i < from + len; i++) {
            valid[i] = true;
        }
        strt = from + len + 1;
        s = strtok(NULL, " ");
    }

    if (!flag) {
        printf("I HAVE FAILED!!!\n");
    } else {
        for (int i = 0; i < n; i++) {
            if (txt[i] != ' ' && valid[i] != true) printf("_");
            else printf("%c", txt[i]);
        }
        printf("\n");
    }

    return 0;
}







