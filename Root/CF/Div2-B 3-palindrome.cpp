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


#define SZ 200010

char s[SZ];

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

//    ios::sync_with_stdio(false);

    int n;
    scanf("%d", &n);

    for (int i = 0, k = 0; i < n; i++, k++) {
        if (k == 4) k = 0;
        if (k == 0) s[i] = 'a';
        else if (k == 1) s[i] = 'a';
        else if (k == 2) s[i] = 'b';
        else if (k == 3) s[i] = 'b';
    }

    s[n] = '\0';
    printf("%s\n", s);

    return 0;
}





