#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  100010


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int q;
    cin >> q;

    for (int cs = 0; cs < q; cs++) {
        string a, b;
        cin >> a >> b;

        int n1 = sz(a), n2 = sz(b);
        vector <bool> mark1(n1, false), mark2(n2, false);

        for (int i = 0, j = 0; i < n1; i++) {
            if (a[i] >= 'A' && a[i] <= 'Z') {
                bool found = false;
                for (; j < n2; j++) {
                    if (b[j] == a[i]) {
                        found = true;
                        mark2[j] = true;
                        j++;
                        break;
                    }
                }
                if (found == false) {
                    cout << "NO" << endl;
                    goto HELL;
                }
            }
        }

        for (int i = 0, j = 0; i < n2; i++) {
            if (mark2[i] == false) {
//                cout << ">> " << i << endl;
                bool found = false;
                for (; j < n1; j++) {
                    if ((a[j] >= 'a' && a[j] <= 'z') && toupper(a[j]) == b[i]) {
                        found = true;
                        mark1[j] = true;
                        j++;
                        break;
                    }
                }
                if (found == false) {
                    cout << "NO" << endl;
                    goto HELL;
                }
            }
        }

        cout << "YES" << endl;
        HELL:;
    }

    return 0;
}



