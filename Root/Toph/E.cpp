#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>
#include <assert.h>
#include <time.h>

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(1010);
    int sz = 0;

    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            cin >> a[sz++];
        } else {
            int req;
            int ans;
            cin >> req;
            bool found = false;
            for (int j = sz - 1; j >= 0; j--) {
                if (a[j] == req) {
                    found = true;
                    ans = sz - j;
                    sz = j;
                    break;
                }
            }
            if (found) cout << ans << endl;
            else cout << "Sorry" << endl;
        }
    }

    return 0;
}




