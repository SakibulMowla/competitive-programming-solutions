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

ll grid[32][32];
int v[32];

void multiply (int n, pii pnt, pii qnt, ll now) {
    for (int k = 0, i = pnt.X, j = pnt.Y; k < n; k++, i++, j++) {
        v[i%n] = j%n;
    }
    if ((pnt.Y - pnt.X + n) % n == (qnt.Y - qnt.X + n) % n) {
        int k = 0;
        while (k == pnt.X || k == qnt.X) k++;
        swap(v[k], v[qnt.X]);
    }
    for (int x = 0; x < n; x++) grid[x][v[x]] *= now;
    return;
}

bool mark[1000000+10];

int main() {
//    #if defined JESI
//        freopen("elegant.in", "r", stdin);
//        freopen("elegant.out", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <int> prime;
    prime.pb(2);

    for (int i = 3; i < 1000; i += 2) {
        if (!mark[i])
        for (int j = i * i; j <= 1000000; j += i) {
            mark[j] = true;
        }
    }

    for (int i = 3; i < 1000000; i += 2) {
        if (mark[i] == false) {
            prime.pb(i);
        }
    }

//    cout << sz(prime) << endl;
//    for (int i = 0; i < 25; i++) {
//        cout << prime[i] << ' ';
//    }
//    cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = 1;
        }
    }

    int indx = 0;

    while (true) {
        bool found = false;
        pii a, b;
        ll mn = numeric_limits <ll>::max();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < n; l++) {
                        if (!(i == k && j == l) && grid[i][j] == grid[k][l] && mn > grid[k][l]) {
                            mn = grid[k][l];
                            a = {i, j};
                            b = {k, l};
                        }
                    }
                }
            }
        }
        if (mn != numeric_limits <ll>::max()) {
            ll now = prime[indx++];
            multiply(n, a, b, now);
            found = true;
        }
        if (!found) {
            break;
        }
    }

//    cout << "Here" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}





