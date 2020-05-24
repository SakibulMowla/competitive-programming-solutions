#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector <int> a(n), seqF(n, 1), seqR(n, 1);

        long long sum = 0;
        for (auto &x: a) cin >> x, sum += x;

        for (int i = 1; i < n; i++) seqF[i] = min(seqF[i - 1] + 1, a[i]);
        reverse(a.begin(), a.end());
        for (int i = 1; i < n; i++) seqR[i] = min(seqR[i - 1] + 1, a[i]);

        int ans = 0;
        for(int i = 0; i < n; i++) ans = max(ans, min(seqF[i], seqR[n - i - 1]) * 2 - 1);

        long long bazinga = ans / 2;
        bazinga = (bazinga + 1) * (bazinga + 1);

        cout << sum - bazinga << endl;
    }

    return 0;
}
