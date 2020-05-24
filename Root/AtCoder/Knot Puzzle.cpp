#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int n, l;
    cin >> n >> l;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 1; i < n; i++) {
        if (a[i] + a[i +1] >= l) {
            cout << "Possible" << endl;
            for (int j = 1; j < i; j++) {
                cout << j << endl;
            } 
            for (int j = n - 1; j >= i; j--) {
                cout << j << endl;
            }
            break;    
        }
        if (i == n - 1) {
            cout << "Impossible" << endl;
        }
    }
    
    return 0;
}

