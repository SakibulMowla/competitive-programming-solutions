#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>
#include <assert.h>
#include <time.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1LL;

#define SZ  1010

int r, c;
int mat[SZ][SZ];

int histogram (vector <int> &a, int n) {
    int ans = 0LL;
    stack <int> stk;
    stk.push(0);

    for (int i = 1; i <= n; i++) {
        int tmp;
        while (a[stk.top()] > a[i] && stk.top()) {
            tmp = a[stk.top()];
            stk.pop();
            tmp *= (i - stk.top() - 1);
            ans = max(ans, tmp);
        }
        stk.push(i);
    }

    while (stk.top()) {
        int tmp = a[stk.top()];
        stk.pop();
        tmp *= (n - stk.top());
        ans = max(ans, tmp);
    }

    return ans;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        scanf("%d %d", &r, &c);

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                char c;
                scanf(" %c", &c);
                mat[i][j] = (c == 'F');
            }
        }

        vector <int> a(c + 1, 0);
        vector <int> ptr(c + 1, -1);
        int ans = 0;

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (mat[i][j] == 1) {
                    if (ptr[j] < i) {
                        ptr[j] = i;
                        while (ptr[j] + 1 <= r && mat[ ptr[j] + 1 ][j] == 1) {
                            ptr[j]++;
                        }
                    }
                    a[j] = ptr[j] - i + 1;
                } else {
                    a[j] = 0;
                }
            }
            ans = max(ans, histogram(a, c));
        }

        printf("%d\n", 3 * ans);
    }

    return 0;
}





