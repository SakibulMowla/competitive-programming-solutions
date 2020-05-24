// CERC 2012
// Problem D: Non-boring sequences
// Naive solution, very fast for random data. O(n^2)
// Author: Jakub Pachocki

#include <cstdlib>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int n;
vector<int> s;
vector<int> previous;
vector<int> next;

bool isUnique(int x, int l, int r) {
    return previous[x] < l && next[x] >= r;
}

bool solve(int l, int r) {
    if (r <= l + 1) {
        return false;
    }
    int x;
    if (rand() % 2) {
        for (x = l; x < r; ++x) {
            if (isUnique(x, l, r)) {
                break;
            }
        }
        if (x == r) {
            return true;
        }
    } else {
        for (x = r - 1; x >= l; --x) {
            if (isUnique(x, l, r)) {
                break;
            }
        }
        if (x == l - 1) {
            return true;
        }
    }
    return solve(l, x) || solve(x + 1, r);
}

bool isBoring(vector<int>& _s) {
    s = _s;
    n = s.size();
    map<int, int> lastSeen;
    previous.assign(n, -1);
    next.assign(n, n);

    for (int i = 0; i < n; ++i) {
        if (lastSeen.find(s[i]) != lastSeen.end()) {
            previous[i] = lastSeen[s[i]];
        }
        lastSeen[s[i]] = i;
    }

    lastSeen.clear();

    for (int i = n - 1; i >= 0; --i) {
        if (lastSeen.find(s[i]) != lastSeen.end()) {
            next[i] = lastSeen[s[i]];
        }
        lastSeen[s[i]] = i;
    }

    return solve(0, n);
}

int main() {
    srand(123456);
    int nCases;
    cin >> nCases;
    for (int i = 0; i < nCases; ++i) {
        int sz;
        cin >> sz;
        vector<int> s(sz);
        for (int j = 0; j < sz; ++j) {
            cin >> s[j];
        }
        cout << (isBoring(s) ? "boring" : "non-boring") << "\n";
    }
}
