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

    int n, a, b;
    cin >> n >> a >> b;

    if (n > a * b) {
        cout << -1 << endl;
    } else {
        stack <int> even, odd;
        for (int i = 1; i <= n; i++) {
            if (i & 1) odd.push(i);
            else even.push(i);
        }

        for (int i = 0, cur = 0; i < a; i++, cur ^= 1) {
            for (int j = 0, tcur = cur; j < b; j++, tcur ^= 1) {
                if (tcur == 0 && sz(odd) != 0) {
                    cout << odd.top() << ' ';
                    odd.pop();
                } else if (tcur == 1 && sz(even) != 0) {
                    cout << even.top() << ' ';
                    even.pop();
                } else {
                    cout << 0 << ' ';
                }
            }
            cout << endl;
        }
    }


    return 0;
}





