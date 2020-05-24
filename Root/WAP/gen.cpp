#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int, int>;
using pll = pair <ll, ll>;

const ll inf = 1;
const ll mod = 1E9;


#define SZ 100010



int main() {
//#if defined JESI
//        freopen("1.txt", "r", stdin);
        freopen("1.txt", "w", stdout);
//#endif

    ios::sync_with_stdio(false);

    int t = 100;
    while (t--) {
    	int n = 1 + (rand() % 100);
    	assert(n >= 1 && n <= 100);
    	cout << n << endl;
    	for (int i = 0; i < n; i++) {
    		ll num = (rand() % 100000000L);
    		assert(num >=0 && num <= 100000000L);
    		cout << num << ' ';
    	}
    	cout << endl;
    }

    return 0;
}

//using VI = vector <int>;
//using VVI = vector <VI>;
//using VVVI = vector <VVI>;
//
//int main() {
////#if defined JESI
////        freopen("1.txt", "r", stdin);
//        freopen("4.txt", "w", stdout);
////#endif
//
//    int t = 100;
//    for (int cs = 0; cs < t; cs++) {
//        int n = rand() % 9 + 2;
//        int m = rand() % 9 + 2;
//        int k = rand() % 5 + 2;
//
//        printf("%d %d %d\n", n, m, k);
//
//        VVVI grid;
//        while (sz(grid) < k) {
//            VVI tmp(n, VI(m));
//            for (int i = 0; i < n; i++) {
//                for (int j = 0; j < m; j++) {
//                    tmp[i][j] = rand() % 2;
//                }
//            }
//            bool flag = true;
//            for (int i = 0; i < grid.size(); i++) {
//                if (grid[i] == tmp) {
//                    flag = false;
//                    break;
//                }
//            }
//            if (flag == true) {
//                grid.push_back(tmp);
//            }
//        }
//
//
//        for (int i = 0; i < k; i++) {
//            printf("\n");
//            for (int r = 0; r < n; r++) {
//                for (int c = 0; c < m; c++) {
//                    printf("%d", grid[i][r][c]);
//                }
//                printf("\n");
//            }
//        }
//        printf("\n");
//    }
//
//    return 0;
//}


