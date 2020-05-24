#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;
using pll = pair <ll , ll>;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 100010

int r, c;
int tmpr[7];
int row[7];
int col[25];
bool vis[21][(1<<5)+1][11][11][11][11][11];
char mat[6][21];
vector <int> store[10];
bool flag = false;

void solve (int cnow, int pmask, int r1, int r2, int r3, int r4, int r5) {
	//cout << ">> " << cnow << ' ' << pmask << '\n';
	//if (cnow == 1 && pmask == 7) cout << "yes\n";
	if (r1 < 0 || r2 < 0 || r3 < 0 || r4 < 0 || r5 < 0) return;
	if (flag) return;
	
	if (vis[cnow][pmask][r1][r2][r3][r4][r5]) return;
	vis[cnow][pmask][r1][r2][r3][r4][r5] = true;
	
	if (cnow == c) {
		if (r1 + r2 + r3 + r4 + r5 == 0) {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					printf("%c", mat[i][j]);
				}
				printf("\n");
			}
			flag = true;
		}
		return;
	}

	for (int i = 0; i < sz(store[col[cnow]]); i++) {
		int nmask = store[col[cnow]][i];
		tmpr[0] = r1; tmpr[1] = r2; tmpr[2] = r3; tmpr[3] = r4; tmpr[4] = r5;
		for (int j = 0; j < r; j++) {
			if (!(pmask & (1<<j)) && (nmask & (1<<j))) {
				tmpr[j]--;
			}
		}
		for (int j = 0; j < r; j++) {
			mat[j][cnow] = (nmask&(1<<j)) ? '*' : '.';
		}
		solve (cnow + 1, nmask, tmpr[0], tmpr[1], tmpr[2], tmpr[3], tmpr[4]);
		if (flag) return;
	}
	
	return;
}

int calc (int mask) {
	int pre = 0, ans = 0;
	for (int i = 0; i < r; i++) {
		if (pre == 0 && (mask & (1<<i))) {
			ans++;
		}
		pre = (mask & (1<<i));
	}
	return ans;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) scanf("%d", &row[i]);
	for (int i = 0; i < c; i++) scanf("%d", &col[i]);
	
	int lim = (1<<r);
	for (int mask = 0; mask < lim; mask++) {
		store[calc(mask)].pb(mask);
	}
	
	solve (0, 0, row[0], row[1], row[2], row[3], row[4]);
	

    return 0;
}






