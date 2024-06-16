#include <bits/stdc++.h>

using namespace std;

int main() {
    int s, b;
    while (cin >> s >> b) {
        if (s == 0 && b == 0) {
            break;
        }

        vector<int> leftOf(s + 1), rightOf(s + 1);
        for (int i = 1; i <= s; i++) {
            leftOf[i] = i - 1;
            rightOf[i] = i + 1;
        }

        while (b--) {
            int l, r;
            cin >> l >> r;

            cout << (leftOf[l] < 1 ? "*" : to_string(leftOf[l])) << " ";
            cout << (rightOf[r] > s ? "*" : to_string(rightOf[r])) << endl;

            leftOf[rightOf[r]] = leftOf[l];
            rightOf[leftOf[l]] = rightOf[r];
        }

        cout << "-" << endl;
    }

    return 0;
}
