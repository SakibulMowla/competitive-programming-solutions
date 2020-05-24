#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int, int>;
using pll = pair <ll, ll>;

const ll inf = 1;
const ll mod = 1E9;


#define SZ 100010


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    vector <string> name(t);
    vector <int> score(t);

    map <string, int> mp1, mp2;

    for (int cs = 0; cs < t; cs++) {
        cin >> name[cs] >> score[cs];
        if (mp1.find(name[cs]) == mp1.end()) {
            mp1[name[cs]] = score[cs];
        } else {
            mp1[name[cs]] += score[cs];
        }
    }

    int mx = 0;
    for (auto &it: mp1) {
        mx = max(mx, it.second);
    }

    string ans;
    for (int cs = 0; cs < t; cs++) {
        if (mp2.find(name[cs]) == mp2.end()) {
            mp2[name[cs]] = score[cs];
        } else {
            mp2[name[cs]] += score[cs];
        }
        if (mp2[name[cs]] >= mx && mp1[name[cs]] == mx) {
            ans = name[cs];
            break;
        }
    }

    cout << ans << endl;

    return 0;
}





