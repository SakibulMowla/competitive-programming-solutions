/*
ID: sakibul1
PROG: ariprog
LANG: C++
*/


#include "bits/stdc++.h"

using namespace std;

#define SZ 125010

bool arr[SZ];

vector < pair <int , int> > ans;

bool comp (pair <int , int> p, pair <int , int> q) {
    if (p.second == q.second) {
        return p.first < q.first;
    }
    return p.second < q.second;
}

int main () {
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int len, lim;
    cin >> len >> lim;

    for (int a = 0; a <= lim; a++) {
        for (int b = a; b <= lim; b++) {
            arr[a*a + b*b] = 1;
        }
    }

    for (int a = 0; a <= 125000; a++) if (arr[a]) {
        for (int b = (125000-a) / (len-1); b > 0; b--) {
            int c;
            for (c = 1; c < len; c++) {
                if (!arr[a + b*c]) {
                    break;
                }
            }
            if (c == len) {
                ans.push_back(make_pair(a, b));
            }
        }
    }

    sort(ans.begin(), ans.end(), comp);

    if (ans.size() == 0) {
        cout << "NONE\n";
    } else {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].first << ' ' << ans[i].second << '\n';
        }
    }

    return 0;
}
