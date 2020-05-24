#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    long long n, x;
    cin >> n >> x;
    
    vector<long long> a(n + n);
    long long ans = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
        ans += a[i];
    }
    
    vector<vector<long long>> minimum(n + n, vector<long long> (n + n, numeric_limits<long long>::max()));
    
    for (int i = 0; i < n + n; i++) {
        minimum[i][i] = a[i];
        for (int j = i + 1; j < n + n; j++) {
            minimum[i][j] = min(a[j], minimum[i][j - 1]);
        }
    }
    
    for (int step = 1; step < n; step++) {
        long long tmp = step * x;
        for (int j = n; j < n + n; j++) {
            tmp += minimum[max(0, j - step)][j];
        }    
        ans = min(ans, tmp);
    }
    
    cout << ans << endl;
    
    return 0;
}
