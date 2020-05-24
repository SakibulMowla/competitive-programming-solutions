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

    int t;
    cin >> t;

    deque<int> dq;
    multiset<int> ms;

    for (int cs = 0; cs < t; cs++) {
        string a, b;
        cin >> a >> b;
        if (a == "Insert") {
            int x;
            cin >> x;
            if (b == "Front") dq.push_front(x);
            else dq.push_back(x);
            ms.insert(x);
        } else if (a == "Erase") {
            if (b == "Front") ms.erase(ms.find(dq.front())), dq.pop_front();
            else ms.erase(ms.find(dq.back())), dq.pop_back();
        } else {
            if (b == "Front") cout << dq.front() << endl;
            else if (b == "Back") cout << dq.back() << endl;
            else if (b == "Max") cout << *prev(ms.end()) << endl;
            else cout << *ms.begin() << endl;
        }
    }

    return 0;
}




