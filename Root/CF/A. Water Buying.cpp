#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    
    for (int cs = 0; cs < t; cs++) {
        ll n, a, b;
        cin >> n >> a >> b;

        ll ans = n * a;
        ans = min(ans, (n / 2) * b + (n % 2) * a);

        cout << ans << endl;
    }

    return 0;
}
