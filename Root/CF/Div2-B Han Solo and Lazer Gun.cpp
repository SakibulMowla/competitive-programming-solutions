#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n, x1, y1;
    cin >> n >> x1 >> y1;

    map <tuple <int, int, int> , int> mp;

    for (int i = 0; i < n; i++) {
        int x2, y2;
        cin >> x2 >> y2;
        tuple <int, int, int> tpl = make_tuple(y1 - y2, x2 - x1, y1 * (x1 - x2) - x1 * (y1 - y2));
        int gcd = __gcd(get<0>(tpl), get<1>(tpl));
        gcd = __gcd(gcd, get<2>(tpl));
        get<0>(tpl) /= gcd;
        get<1>(tpl) /= gcd;
        get<2>(tpl) /= gcd;
        mp[tpl] = 1;
    }

    cout << mp.size() << endl;

    return 0;
}
