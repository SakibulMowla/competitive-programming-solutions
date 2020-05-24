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

char a[SZ], *s;

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

//    ios::sync_with_stdio(false);

    int cs = 0;
    while (scanf(" %s", a) == 1) {
        if (strcmp(a, "#") == 0) break;

        s = strtok(a, ".");
        while (s != NULL) {
            s = strtok(NULL, ".");
            break;
        }

        int n = strlen(s);
        s[n] = 'x';
        s[n+1] = '\0';

        int up = 0, down = 0, nc = 0, amb = 0;
        n = strlen(s);

        for (int j = n - 2; j >= 0; j--) {
            if (s[j] == '0') {
                nc++;
                s[j] = 'x';
            } else {
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (s[i] == 'x') break;
            if (s[i] == '5' && s[i+1] == 'x') {
                amb++;
            }
            else {
                if (s[i] <= '4') down++;
                else up++;
            }
        }

        printf("Case %d:\n", ++cs);
        printf("ROUND UP: %d\nROUND DOWN: %d\nNO CHANGE: %d\nAMBIGUOUS: %d\n\n", up, down, nc, amb);
    }


    return 0;
}




