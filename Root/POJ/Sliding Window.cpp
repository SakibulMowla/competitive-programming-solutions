#include <stdio.h>
#include <vector>
#include <deque>
#include <iostream>

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

#define SZ  110

void sliding_window_minimum(std::vector<int> & ARR, int K) {
    // pair<int, int> represents the pair (ARR[i], i)
    deque< std::pair<int, int> > window;
    bool blank = false;

    for (int i = 0; i < ARR.size(); i++) {
        while (!window.empty() && window.back().first >= ARR[i])
            window.pop_back();
        window.push_back(std::make_pair(ARR[i], i));

        while(window.front().second <= i - K)
            window.pop_front();

        if (i < K - 1) continue;

        if (blank) cout << ' ';
        else blank = true;
        cout << (window.front().first);
    }
    cout << '\n';
}

void sliding_window_maximum(std::vector<int> & ARR, int K) {
    // pair<int, int> represents the pair (ARR[i], i)
    deque< std::pair<int, int> > window;
    bool blank = false;

    for (int i = 0; i < ARR.size(); i++) {
        while (!window.empty() && window.back().first <= ARR[i])
            window.pop_back();
        window.push_back(std::make_pair(ARR[i], i));

        while(window.front().second <= i - K)
            window.pop_front();

        if (i < K - 1) continue;

        if (blank) cout << ' ';
        else blank = true;
        cout << (window.front().first);
    }
    cout << '\n';
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector <int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sliding_window_minimum(a, k);
    sliding_window_maximum(a, k);

    return 0;
}
