#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int n, l;
map<string, bool> mp;
vector<set<char>> vsc;
bool found;
string ans, s;

void bctk(int indx) {
    if (found) return;
    if (indx == l) {
        if (mp.find(s) == mp.end()) {
            ans = s;
            found = true;
        }
    } else {
        for (auto c: vsc[indx]) {
            s.push_back(c);
            bctk(indx + 1);
            s.pop_back();
            if (found) return;
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        cin >> n >> l;

        vector<string> words(n);
        vsc = vector<set<char>> (l);
        mp.clear();
        for (int i = 0; i < n; i++) {
            cin >> words[i];
            mp[words[i]] = true;
        }
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < n; j++) {
                vsc[i].insert(words[j][i]);
            }
        }

        ans = "-";
        s = "";
        found = false;
        bctk(0);

        cout << "Case #" << cs + 1 << ": " << ans << endl;
    }

    return 0;
}

