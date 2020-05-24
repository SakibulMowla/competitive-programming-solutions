#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;

typedef vector <int> VI;

typedef vector <bool> VB;
typedef vector <VB> VBB;
typedef vector <VBB> VBBB;

struct Solve {
    int N;
    int n, m, k;
    int ans;
    char ch;
    VBBB grid;
    VI types;
    VI IDs;
    stack <int> stk;

    Solve(int n, int m, int k): n(n), m(m), k(k), grid(k, VBB(n, VB(m))) {
        for (int i = 0; i < k; i++) {
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < m; c++) {
                    scanf(" %c", &ch);
                    grid[i][r][c] = (ch - '0') & 1;
                }
            }
        }

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                int now = 0;
                for (int i = 0; i < k; i++) {
                    now = (now << 1) | (grid[i][r][c] & 1);
                }
                types.push_back(now);
            }
        }

        sort(types.begin(), types.end());
        types.resize(unique(types.begin(), types.end()) - types.begin());

        N = types.size();
        ans = k - 1;
        IDs = VI(k, 0);

        rec(ans - 1, N - 1);
        printf("%d\n", ans);
    }

    bool is_satisfied() {
        set <int> ms;
        for (int i = 0; i < k; i++) {
            ms.insert(IDs[i]);
        }
        return (int)ms.size() == k;
    }

    void rec(int depth, int indx) {
        if ((int)stk.size() >= ans) return;
        if (is_satisfied()) {
            ans = min(ans, (int)stk.size());
            return;
        }
        if (depth <= 0 || indx < 0) return;

        rec(depth, indx - 1);

        stk.push(types[indx]);
        for (int i = 0; i < k; i++) {
            IDs[i] = (IDs[i] << 1) | ((types[indx] >> i) & 1);
        }

        rec(depth - 1, indx - 1);

        for (int i = 0; i < k; i++) {
            IDs[i] = (IDs[i] >> 1);
        }
        stk.pop();

        return;
    }
};

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    Solve sol(n, m, k);

    return 0;
}


/*
d76e9c4b-0a83-46da-999b-483fbbc68f6c
*/
