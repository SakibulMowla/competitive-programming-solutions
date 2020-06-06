#include <iostream>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
 
    int tests;
    cin >> tests;
 
    while (tests--) {
        int n, m, k;
        cin >> n >> m >> k;
 
        int first = min(n / k, m);
        m -= first;
        int second = (m / (k - 1)) + (bool)(m % (k - 1));
 
        cout << first - second << '\n';
    }
 
    return 0;
}
