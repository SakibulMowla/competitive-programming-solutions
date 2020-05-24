/*
ID: sakibul1
PROG: milk3
LANG: C++
*/

#include "bits/stdc++.h"

using namespace std;

int a, b, c;
bool arr[21][21][21];

void dfs (int p, int q, int r) {
    if (arr[p][q][r]){
        return;
    } else {
        arr[p][q][r] = 1;
    }

    if (p + q > b) {
        dfs (p + q - b, b, r);
    } else {
        dfs (0, p + q, r);
    }

    if (p + r > c) {
        dfs (p + r - c, q, c);
    } else {
        dfs (0, q, p + r);
    }

    if (q + p > a) {
        dfs (a, q + p - a, r);
    } else {
        dfs (q + p, 0, r);
    }

    if (q + r > c) {
        dfs (p, q + r - c, c);
    } else {
        dfs (p, 0, q + r);
    }

    if (r + p > a) {
        dfs (a, q, r + p - a);
    } else {
        dfs (r + p, q, 0);
    }

    if (r + q > b) {
        dfs (p, b, r + q - b);
    } else {
        dfs (p, r + q, 0);
    }
}

int main() {
    ios::sync_with_stdio(0);

    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);


    cin >> a >> b >> c;

    memset(arr, 0, sizeof arr);

    dfs (0, 0, c);

    bool blank = false;
    for (int i = 0; i <= c; i++) {
        if (arr[0][c-i][i] == 1) {
            if (blank) cout << ' ';
            else blank = 1;
            cout << i;
        }
    }
    cout << '\n';
}
