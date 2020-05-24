// CERC 2012
// Problem K: Graphic Madness
// Model solution, O(n)
// Author: Jakub Pachocki

#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int decode(const string& name, int k, int n, int m) {
    int result = 0;
    char card;
    char type;
    stringstream ss(name);
    ss >> card >> type >> result;
    --result;
    if (type == 'P') {
        result += k;
    }
    if (card == 'B') {
        result += k + n;
    }
    return result;
}

string encode(int x, int k, int n, int m) {
    stringstream result;
    if (x >= k + n) {
        result << 'B';
        x -= k + n;
    } else {
        result << 'A';
    }
    if (x >= k) {
        result << 'P';
        x -= k;
    } else {
        result << 'S';
    }
    result << x + 1;
    return result.str();
}

int dfs(int x, vector<vector<int> >& e, int l, int r, int k, int parent = -1) {
    if (x < l + k) {
        if (e[x][0] >= l && e[x][0] < r) {
            swap(e[x][0], e[x][1]);
        }
        e[x].pop_back();
        return 1;
    }
    for (int i = 0; i < (int) e[x].size(); ++i) {
        int ex = 0;
        if (e[x][i] != parent && ((ex = dfs(e[x][i], e, l, r, k, x)) == 1)) {
            e[e[x][i]].push_back(x);
        } else {
            if (ex == -1) {
                return -1;
            }
            swap(e[x][i], e[x].back());
            e[x].pop_back();
            --i;
        }
    }
    if ((int) e[x].size() < 1 || (int) e[x].size() > 2) {
        return -1;
    }
    return (int) e[x].size() == 1;
}

bool prune(vector<vector<int> >& e, int l, int r, int k) {
    return dfs(l + k, e, l, r, k) == 0;
}

void alg() {
    int k, n, m;
    cin >> k >> n >> m;
    vector<vector<int> > e(2 * k + n + m);
    for (int i = 0; i < 3 * k + n + m - 2; ++i) {
        string a, b;
        cin >> a >> b;
        int x = decode(a, k, n, m);
        int y = decode(b, k, n, m);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    {
        if (!prune(e, 0, n + k, k)) {
            goto bad;
        }
        if (!prune(e, n + k, n + m + 2 * k, k)) {
            goto bad;
        }
        for (int i = 0; i < n + m + 2 * k; ++i) {
            if ((int) e[i].size() != 2) {
                goto bad;
            }
        }
        vector<int> path;
        int prev = -1;
        int c = 0;
        do {
            path.push_back(c);
            if (e[c][0] == prev) {
                prev = c;
                c = e[c][1];
            } else {
                prev = c;
                c = e[c][0];
            }
        } while (c != 0);
        if ((int) path.size() != n + m + 2 * k) {
            goto bad;
        }
        cout << "YES";
        for (int i = 0; i < (int) path.size(); ++i) {
            cout << " " << encode(path[i], k, n, m);
        }
        cout << "\n";
    }
    return;
    bad:
    cout << "NO" << "\n";
}

int main() {
    int n_testcases;
    cin >> n_testcases;
    for (int testcase = 0; testcase < n_testcases; ++testcase) {
        alg();
    }
}
