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
const ll mod = 1E9 + 7;


#define SZ 10000010

int findMedian(int i, int j, vector <int>& a) {
    int r = j - i + 1, median;
    if (r & 1) {
        median = a[i + r / 2];
    } else {
        median = (a[i + r / 2] + a[i + r / 2 - 1]) / 2;
    }
    return median;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <int> a(n);
    for (auto &x: a) cin >> x;

    sort(a.begin(), a.end());

    int Q1 = findMedian(0, n / 2 - 1, a);
    int Q2 = findMedian(0, n - 1, a);
    int Q3 = findMedian(n / 2 + (n & 1), n - 1, a);

    cout << Q1 << endl;
    cout << Q2 << endl;
    cout << Q3 << endl;

    return 0;
}




