#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void assignColors(vector<int>& types, vector<int>& colors, int startingIndex, int n) {
    for (int i = startingIndex; i < n; i++) {
        if (types[i] == types[i - 1]) {
            colors[i] = colors[i - 1];
        } else {
            colors[i] = !colors[i - 1];
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);

    int tests;
    cin >> tests;

    while (tests--) {
        int n;
        cin >> n;

        vector<int> types(n), colors(n);
        int secondIndexOfConsecutiveSameType = -1;

        for (int i = 0; i < n; i++) {
            cin >> types[i];

            if (i && types[i] == types[i - 1]) {
                secondIndexOfConsecutiveSameType = i;
            }
        }

        colors[0] = 0;
        assignColors(types, colors, 1, n);

        if (types[0] != types[n - 1] && colors[0] == colors[n - 1]) {
            if (secondIndexOfConsecutiveSameType != -1) {
                colors[secondIndexOfConsecutiveSameType] = !colors[secondIndexOfConsecutiveSameType - 1];
                assignColors(types, colors, secondIndexOfConsecutiveSameType + 1, n);
            } else {
                colors[n - 1] = 2;
            }
        }

        cout << 1 + *max_element(colors.begin(), colors.end()) << endl;
        for (auto x: colors) {
            cout << 1 + x << ' ';
        }
        cout << endl;
    }

    return 0;
}
