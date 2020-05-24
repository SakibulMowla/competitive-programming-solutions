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


#define SZ 1000010

char s[SZ];
vector <string> words[SZ];

int main() {
    vector <int> cnt(1000010, 0);

    scanf("%s", s);
    int mx = 0, lev = 0;
    char *ch = strtok(s, ",");

    int toggle = 1;
    while (ch != NULL) {
        if (toggle) {
            string str = ch;
            words[lev].pb(str);
            cnt[lev]--;
        } else {
            int num = atoi(ch);
            if (num > 0) lev++, cnt[lev] += num;
            else {
                while (lev != 0 && cnt[lev] == 0) lev--;
            }
        }
        toggle ^= 1;
        ch = strtok(NULL, ",");
        mx = max(mx, lev);
    }

    printf("%d\n", mx + 1);
    for (int i = 0; i <= mx; i++) {
        for (int j = 0; j < sz(words[i]); j++) {
            printf("%s ", words[i][j].c_str());
        }
        printf("\n");
    }

    return 0;
}





