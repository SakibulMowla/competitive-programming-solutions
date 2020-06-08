#include <iostream>
#include <limits>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

string toBinary(ll n) {
    string s;
    while (n) {
        s += (n % 2) + '0';
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

int convert(string a, string b) {
    int minLength = min(a.size(), b.size());
    for (int i = 0; i < minLength; i++) {
        if (a[i] != b[i]) {
            return -1;
        }
    }

    int cnt = 0;

    for (int i = minLength; i < a.size(); i++) {
        if (a[i] != '0') {
            return -1;
        }
        cnt++;
    }

    for (int i = minLength; i < b.size(); i++) {
        if (b[i] != '0') {
            return -1;
        }
        cnt++;
    }

    return (cnt / 3) + (bool)(cnt % 3);
}

int main() {
    ios::sync_with_stdio(false);

    int tests;
    cin >> tests;

    while (tests--) {
        ll a, b;
        cin >> a >> b;

        string aBinary = toBinary(a), bBinary = toBinary(b);

        cout << convert(aBinary, bBinary) << '\n';
    }

    return 0;
}
