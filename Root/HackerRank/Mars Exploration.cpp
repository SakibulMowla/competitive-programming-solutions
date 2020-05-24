#include <bits/stdc++.h>

using namespace  std;

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i % 3 == 0 && s[i] != 'S') ans++;
        else if (i % 3 == 1 && s[i] != 'O') ans++;
        else if (i % 3 == 2 && s[i] != 'S') ans++;
    }

    cout << ans << endl;

    return 0;
}


