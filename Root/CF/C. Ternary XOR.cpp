#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string x;
        cin >> x;

        string a, b;

        for (int i = 0; i < n; i++) {
            if (x[i] == '0') {
                a += '0';
                b += '0';
            } else if (x[i] == '2') {
                a += '1';
                b += '1';
            } else {
                a += '1' + string(n - i - 1, '0');
                b += '0' + x.substr(i + 1);
                break;
            }
        }

        cout << a << endl << b << endl;
    }

    return 0;
}
