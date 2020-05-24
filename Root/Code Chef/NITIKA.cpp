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
        char s[100], a[10], b[10], c[10];
        scanf(" %[^\n]", s);
        int parts = sscanf(s, "%s %s %s", a, b, c);
        if (parts == 1) {
            a[0] = toupper(a[0]);
            for (int i = 1; i < strlen(a); i++) a[i] = tolower(a[i]);
            printf("%s\n", a);
        } else if (parts == 2) {
            a[0] = toupper(a[0]); a[1] = '.'; a[2] = '\0';
            b[0] = toupper(b[0]);
            for (int i = 1; i < strlen(b); i++) b[i] = tolower(b[i]);
            printf("%s %s\n", a, b);
        } else {
            a[0] = toupper(a[0]); a[1] = '.'; a[2] = '\0';
            b[0] = toupper(b[0]); b[1] = '.'; b[2] = '\0';
            c[0] = toupper(c[0]);
            for (int i = 1; i < strlen(c); i++) c[i] = tolower(c[i]);
            printf("%s %s %s\n", a, b, c);
        }
    }

    return 0;
}




