#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        string s;
        cin >> n >> s;

        stack < pair <char, int> > stk;
        ll ans = 0LL, cnt = 0LL;

        for (int i = 0; i < n; i++) {
            if (s[i] == '4') {
                if (i + 1 < n && s[i + 1] == '7') {
                    cnt += 2;
                }
            }
            if (s[i] == '7' && !stk.empty() && stk.top().first == '4') {
                ans += (ll)stk.top().second;
                stk.pop();
            } else {
                stk.push({s[i], i + 1});
            }
        }

        cout << ans << endl;
    }

    return 0;
}

