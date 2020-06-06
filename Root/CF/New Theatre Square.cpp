#include <iostream>
 
using namespace std;
 
const char BLACK = '*';
const char WHITE = '.';
 
int prune(int n, int m, int x) {
    int whiteCount = 0;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            whiteCount += ch == WHITE;
        }
    }
 
    return whiteCount * x;
}
 
int solve(int n, int m, int x, int y) {
    int cost = 0;
 
    for (int i = 0; i < n; i++) {
        int adjCount = 0;
 
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
 
            if (ch == WHITE) {
                adjCount++;
            } else {
                cost += (adjCount / 2) * y + (adjCount % 2) * x;
                adjCount = 0;
            }
        }
 
        cost += (adjCount / 2) * y + (adjCount % 2) * x;
    }
 
    return cost;
}
 
int main() {
    ios::sync_with_stdio(false);
 
    int tests;
    cin >> tests;
 
    while (tests--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
 
        int ans = (y > 2 * x) ? prune(n, m, x) : solve(n, m, x, y);
        cout << ans << '\n';
    }
 
    return 0;
}
