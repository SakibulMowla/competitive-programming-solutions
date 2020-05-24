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

struct data {
	int x, y, z;
	data () {}
	data(int a, int b, int c) {
		x = a, y = b, z = c;
	}
};

data dice[50];
char str[50];

data parse(char *s) {
	int x, y, z = 0;
	int sign = 1;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == '-') {
			sign = -1;
			break;
		}
	}
	char *p;
	p = strtok(s, "d+-");
	int cnt = 0;
	while (p != NULL) {
		if (cnt == 0) x = atoi(p);
		else if (cnt == 1) y = atoi(p);
		else z = atoi(p);
		p = strtok(NULL, "d+-");
		cnt++;
	}
	data tmp = { x, y, z * sign};
	return tmp;
}

bool col[22][810][22];
double dp[22][810][22];

double solve(int times, int sides, int target) {
	if (times == 0) return (double)(target <= 400);
	if (col[times][target][sides]) return dp[times][target][sides];

	col[times][target][sides] = 1;
	dp[times][target][sides] = 0;
	for (int i = 1; i <= sides; i++) {
		dp[times][target][sides] += solve(times - 1, sides, target - i);
	}

	return dp[times][target][sides];
}

double cal (int times, int sides, int target) {
	if (target > times * sides) return 0;
	if (target <= 0) return 1;
	double ans = solve(times, sides, target + 400);
	for (int i = 0; i < times; i++) {
		ans /= (double)sides;
	}
	return ans;
}

int main() {
//#if defined JESI
//	        freopen("fighting_the_zombie.txt", "r", stdin);
//	        freopen("2.txt", "w", stdout);
//#endif

//	ios::sync_with_stdio(false);

	memset(col, 0, sizeof col);

	int t;
	scanf("%d", &t);

	for (int cs = 0; cs < t; cs++) {
		int h, s;
		scanf("%d %d", &h, &s);

//        cout << cs << endl;

		for (int i = 0; i < s; i++) {
			scanf("%s", str);
			dice[i] = parse(str);
		}

//        cout << cs << endl;

		double ans = 0;
		for (int i = 0; i < s; i++) {
			ans = max(ans, cal(dice[i].x, dice[i].y, h - dice[i].z));
		}

//		printf("Case #%d: %.12lf\n", cs + 1, ans);
		cout << "Case #" << cs + 1 << ": " << fixed << setprecision(12) << ans << endl;
	}

	return 0;
}




