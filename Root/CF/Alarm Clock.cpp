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
//    #if defined JESI
        freopen("alarm.in", "r", stdin);
        freopen("alarm.out", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    vector <int> cnt(12, 0);
    cnt[0] = 6;
    cnt[1] = 2;
    cnt[2] = 5;
    cnt[3] = 5;
    cnt[4] = 4;
    cnt[5] = 5;
    cnt[6] = 6;
    cnt[7] = 3;
    cnt[8] = 7;
    cnt[9] = 6;

    int n;
    cin >> n;

    bool flag = false;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) if (i * 10 + j < 24) {
            for (int k = 0; k < 10; k++) {
                for (int l = 0; l < 10; l++) if (k * 10 + l < 60) {
                    if (cnt[i] + cnt[j] + cnt[k] + cnt[l] == n) {
                        flag = true;
                        cout << i << j << ":" << k << l << endl;
                        i = j = k = l = 10;
                    }
                }
            }
        }
    }
    if (!flag) {
        cout << "Impossible" << endl;
    }

    return 0;
}





