#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define pb push_back
#define sz(a) (int)a.size()

#define SZ 100010

const ll inf = 1;
const ll mod = 1;



int main () {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int p, q;
        cin >> p >> q;
        cout << ((q - p <= 6 && q - p >= 1)? "Yes": "No") << endl;
    }

    return 0;
}

