#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  1000010

int sliding_window_minimum(std::vector<int> &ARR, int n) {
    deque<pii> window;
    int ans = 0;

    for (int i = 1; i < sz(ARR) - 1; i++) {
        while (!window.empty() && window.back().first >= ARR[i])
            window.pop_back();

        window.push_back(MP(ARR[i], i));

        while(window.front().second <= i - n)
            window.pop_front();

        if (i >= n && window.front().first >= ARR[i-n])
            ans++;
    }

    return ans;
}

int main() {
    #if defined JESI
    //    freopen("1.txt", "r", stdin);
    //    freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector <int> a;

    while(cin >> n && n) {
        a = vector <int> (2*n + 1);
        a[0] = 0;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i+n] = a[i];
        }
        for (int i = 1; i <= n + n; i++) {
            a[i] += a[i-1];
        }

        printf("%d\n", sliding_window_minimum(a, n));
    }


    return 0;
}






