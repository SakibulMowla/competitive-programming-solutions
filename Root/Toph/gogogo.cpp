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

using pii = pair<int, int>;
using piii = pair<int, pii>;

int main() {
    ios::sync_with_stdio(false);

    priority_queue<piii> pq;

    pq.push({0, {1, 2}});
    pq.push({3, {1, 3}});
    pq.push({-4, {1, 3}});
    pq.push({0, {1, 3}});
    pq.push({-10, {1, 3}});

    while (!pq.empty()) {
        cout << pq.top().first << ' ' << pq.top().second.first << ' ' << pq.top().second.second << endl;
        pq.pop();
    }

    return 0;
}


