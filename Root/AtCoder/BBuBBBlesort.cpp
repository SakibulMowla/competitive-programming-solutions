#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    map<int, int> mp;
    
    for (auto& x: a) {
        cin >> x;
        mp[x] = 1;
    }
    
    int cnt = 0;
    for (auto& it: mp) {
        it.second = cnt++;
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int diff = abs(i - mp[a[i]]);
        ans += (diff & 1);
    }
    cout << ans / 2 << endl;
    
    return 0;
}

