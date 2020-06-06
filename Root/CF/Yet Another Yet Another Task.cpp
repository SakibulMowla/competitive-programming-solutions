#include <iostream>
#include <limits>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

int curatedKadane(vector<int>& a, int element) {
    int ans = numeric_limits<int>::min();
    int sum = 0;

    for (auto x: a) {
        if (x > element) {
            sum = 0;
        } else {         
            sum += x;
            ans = max(ans, sum - element);

            if (sum < 0) {
                sum = 0;
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    set<int> uniqueElements;

    for (int& x: a) {
        cin >> x;
        uniqueElements.insert(x);
    }

    int ans = numeric_limits<int>::min();
    for (auto element: uniqueElements) {
        ans = max(ans, curatedKadane(a, element));
    }

    cout << ans << '\n';

    return 0;
}
