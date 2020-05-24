#include <stdio.h>
#include <vector>
#include <iostream>

using namespace  std;

int main() {
//    #if defined JESI
        freopen("A-large.in", "r", stdin);
        freopen("2.txt", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        vector<int> cnt(5002, 0);
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            cnt[a]++;
            cnt[b + 1]--;
        }

        for (int i = 1; i <= 5000; i++) {
            cnt[i] += cnt[i - 1];
        }

        int p;
        cin >> p;

        cout << "Case #" << cs + 1 << ":";
        while (p--) {
            int x;
            cin >> x;
            cout << ' ' << cnt[x];
        }
        cout << endl;
    }

    return 0;
}



