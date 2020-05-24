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
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        string a, b;
        cin >> a >> b;

        int oneToZero = 0, zeroToOne = 0;
        bool isZero = false, isOne = false;

        for (int i = 0; i < sz(a); i++) {
            if (a[i] == '0' && b[i] == '1') zeroToOne++;
            if (a[i] == '1' && b[i] == '0') oneToZero++;
            if (a[i] == '0') isZero = true;
            else isOne = true;
        }

        int ans = min(oneToZero, zeroToOne);

        oneToZero -= ans;
        zeroToOne -= ans;

        if (oneToZero) {
            if (isZero) {
                ans += oneToZero;
                oneToZero = 0;
            }
        }
        if (zeroToOne) {
            if (isOne) {
                ans += zeroToOne;
                zeroToOne = 0;
            }
        }

        if (!oneToZero && !zeroToOne) {
            cout << "Lucky Chef" << endl;
            cout << ans << endl;
        } else {
            cout << "Unlucky Chef" << endl;
        }
    }


    return 0;
}





