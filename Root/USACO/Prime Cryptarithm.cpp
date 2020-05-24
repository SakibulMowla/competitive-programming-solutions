/*
ID: sakibul1
PROG: crypt1
LANG: C++
*/


#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

vector <int> v;
map <int , int> mp;

bool chk1 (int n) {
    while (n) {
        if (mp.find(n%10) == mp.end())
            return false;
        n /= 10;
    }
    return true;
}

bool chk2 (int n) {
    int len = 0;
    while (n) {
        len++;
        n /= 10;
    }
    return (len == 3);
}

bool chk3 (int n) {
    int len = 0;
    while (n) {
        len++;
        n /= 10;
    }
    return (len == 4);
}

int main () {
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);

    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (val < 10 && val > 0) {
            mp[ val ] = 1;
            v.push_back(val);
        }
    }

    sort(v.begin(), v.end());
    n = unique(v.begin(), v.end()) - v.begin();

    int ans = 0;

    for (int a = 0; a < n; a++)
    for (int b = 0; b < n; b++)
    for (int c = 0; c < n; c++)
    for (int d = 0; d < n; d++)
    for (int e = 0; e < n; e++) {
        if (chk2((v[a]*100 + v[b]*10 + v[c]) * v[d]) && chk2((v[a]*100 + v[b]*10 + v[c]) * v[e]) && chk1((v[a]*100 + v[b]*10 + v[c]) * v[e]) && chk1((v[a]*100 + v[b]*10 + v[c]) * v[d]) && chk1((v[a]*100 + v[b]*10 + v[c]) * (v[d]*10 + v[e]))) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
