#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)x.size()


int main() {
    ios::sync_with_stdio(false);

    int tt;
    cin >> tt;

    for (int cs = 0; cs < tt; cs++) {
        string s, t = "";
        cin >> s;

        for (auto ch: s) {
            if (ch >= '0' && ch <= '9') {
                string tmp = t;
                if (ch == '0') t = "";
                else
                    for (int i = 2; i <= (ch - '0'); i++) {
                        t = t + tmp;
                    }
            } else {
                t += ch;
            }
        }

        int q;
        cin >> q;

        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            if (x > sz(t)) cout << -1 << endl;
            else cout << t[x - 1] << endl;
        }
    }


    return 0;
}





