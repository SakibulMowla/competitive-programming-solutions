#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using VI = vector<int>;

VI prepare(int n, VI& input) {
    VI result(n, 0);
    for (int i = 0; i < n; i++) {
        result[i] = input[i] + (i - 2 >= 0 ? result[i - 2] : 0);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    VI input(n);
    for (auto &x: input) {
        cin >> x;
    }

    VI prefix = prepare(n, input);
    reverse(input.begin(), input.end());
    VI suffix = prepare(n, input);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int last = 0, second_last = 0, i_prime = n - i - 1;
        if (i - 1 >= 0) last = prefix[i - 1];
        if (i - 2 >= 0) second_last = prefix[i - 2];
        if (i_prime - 1 >= 0) second_last += suffix[i_prime - 1];
        if (i_prime - 2 >= 0) last += suffix[i_prime - 2];
        if (last == second_last) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}