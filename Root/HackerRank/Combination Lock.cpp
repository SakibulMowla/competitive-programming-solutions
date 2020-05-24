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

int getNum (vector <int> &a) {
    return a[0] * 10000 + a[1] * 1000 + a[2] * 100 + a[3] * 10 + a[4];
}

int next (int n, int dir) {
    return (n + dir + 10) % 10;
}

int bfs (vector <int>& a, vector <int>& b) {
    queue <vector <int>> q;
    vector <int> d(100010, -1);
    d[getNum(a)] = 0;
    q.push(a);
    while (!q.empty()) {
        vector <int> u = q.front(); q.pop();
        int r = getNum(u);
        for (int i = 0; i < 5; i++) {
            for (int j = -1; j <= 1; j += 2) {
                int tmp = u[i];
                u[i] = next(u[i], j);
                int x = getNum(u);
                if (d[x] == -1) {
                    d[x] = d[r] + 1;
                    q.push(u);
                }
                u[i] = tmp;
            }
        }
    }
    return d[getNum(b)];
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    vector <int> a(5), b(5);
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 5; i++) {
        cin >> b[i];
    }

    cout << bfs(a, b) << endl;

    return 0;
}



