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

struct SolveC {
    int n;
    int s;
    int t;
    vector <ll> r;
    int g;
    int seed;
    int p;

    int rightPtr;
    int pseudoRightPtr;
    int leftPtr;
    int pseudoLeftPtr;

    struct Pointer {
        int next, prev;
    };

    vector <Pointer> arr;

    SolveC(int n, int s, int t): n(n), s(s), t(t), r(n), arr(n) {
        cin >> r[0] >> g >> seed >> p;

        for (int i = 1; i < n; i++) r[i] = (r[i - 1] * g + seed) % p;

        for (int i = 0; i < n; i++) arr[i].next = i + 1;
        for (int i = 0; i < n; i++) arr[i].prev = i - 1;

        rightPtr = s;
        leftPtr = s;

        cout << BFS(s, t) << endl;
    }

    int BFS(int s, int t) {
        queue <int> Q;
        Q.push(s);
        vector <int> dist(n, numeric_limits <int> :: max());
        dist[s] = 0;

        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            if (u == t) return dist[u];

//            cout << ">> " << u << endl;

            int expandRight = u + r[u];
            int expandLeft = u - r[u];

            for (int i = rightPtr + 1; i <= min(expandRight, n - 1); i = arr[i].next) {
                if (dist[i] > dist[u] + 1) {
                    dist[i] = dist[u] + 1;
                    Q.push(i);
                }
                arr[i].prev = s;
                rightPtr = i;
//                cout << "i1 = " << i << endl;
            }

            for (int i = leftPtr - 1; i >= max(0, expandLeft); i = arr[i].prev) {
                if (dist[i] > dist[u] + 1) {
                    dist[i] = dist[u] + 1;
                    Q.push(i);
                }
                arr[i].next = s;
                leftPtr = i;
//                cout << "i2 = " << i << endl;
            }

            if (expandRight >= n) {
                int extra = expandRight - n + 1;
                                int last = numeric_limits <int> :: max();

                for (int i = 0; i < min(extra, s); i = arr[i].next) {
                    if (dist[i] > dist[u] + 1) {
                        dist[i] = dist[u] + 1;
                        Q.push(i);
                    }
//                    arr[0].next = i;
//                    cout << "i3 = " << i << endl;
                }
                if (last != numeric_limits <int> :: max()) {
                    arr[0].next = last;
                }
            }

            if (expandLeft < 0) {
                int extra = -expandLeft;
//                cout << ">>> " << n - 1 - extra << endl;
//                cout << ">>> " << arr[n - 1].prev << endl;
                int last = numeric_limits <int> :: max();
                for (int i = n - 1; i > max(s, n - 1 - extra); i = arr[i].prev) {
                    if (dist[i] > dist[u] + 1) {
                        dist[i] = dist[u] + 1;
                        Q.push(i);
                    }
//                    arr[n - 1].prev = i;
                    last = i;
//                    cout << "i4 = " << i << endl;
                }
                if (last != numeric_limits <int> :: max()) {
                    arr[n - 1].prev = last;
                }
            }
        }

        return -1;
    }
};

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n, s, t;
    cin >> n >> s >> t;

    SolveC C(n, s, t);

    return 0;
}


