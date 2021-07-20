#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int y;
    while (cin >> y) {
        int p;
        cin >> p;

        vector<int> popes(p);
        for (int& pope: popes) {
            cin >> pope;
        }

        sort(popes.begin(), popes.end());

        int maxPopes = 0;
        int startYear;
        int endYear;

        for (int l = 0, r = 0; l < p; l++) {
            while (r + 1 < p && popes[r + 1] - popes[l] + 1 <= y) {
                r++;
            }
            if (r - l + 1 > maxPopes) {
                maxPopes = r - l + 1;
                startYear = popes[l];
                endYear = popes[r];
            }
        }

        cout << maxPopes << ' ' << startYear << ' ' << endYear << endl;
    }

    return 0;
}
