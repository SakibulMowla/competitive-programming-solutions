#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1LL;

#define SZ  100010

class RobotOnMoon {
public:
    int longestSafeCommand(vector <string> board) {
//        printf("%d %d\n", sz(board), sz(board[0]));
        int sx, sy;
        for (int i = 0; i < sz(board); i++) {
            for (int j = 0; j < sz(board[0]); j++) {
                if (board[i][j] == 'S') {
                    sx = i;
                    sy = j;
                    i = sz(board);
                    j = sz(board[0]);
                }
            }
        }
//        printf("%d %d\n", sx, sy);
        for (int i = 0; i < sz(board); i++) {
            for (int j = 0; j < sz(board[i]); j++) {
                if (board[i][j] == '#' && (sx == i || sy == j)) {
                    return -1;
                }
            }
        }
        return sz(board) + sz(board[0]) - 2;
    }

};
