#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].X;
        a[i].Y = i + 1;
    }
    sort(a.begin(), a.end());
    
    set<int> ms;
    ms.insert(0);
    ms.insert(n + 1);
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int l = *prev(ms.lower_bound(a[i].Y));
        int r = *ms.upper_bound(a[i].Y);
        ans += (ll)a[i].X * (a[i].Y - l) * (r - a[i].Y);
        ms.insert(a[i].Y);
    }
    
    cout << ans << endl;
    
    return 0;
}
