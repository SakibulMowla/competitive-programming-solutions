#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
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

#define SZ 22

struct data {
	int a, b, c;
};

bool comp(data p, data q) {
	/*if (p.c == q.c) {
		if (p.a == q.a) {
			return p.b < q.b;
		}
		return p.a < q.a;
	}*/
	return p.c < q.c;
}

data v[SZ*SZ];
int judges[SZ];
int par[SZ];
vector <pii> adj[SZ];
vector <pii> nadj[SZ];

int Find (int r) {
	if (r == par[r]) return r;
	return par[r] = Find(par[r]);
}

void MST (int edges) {
	for (int i = 0; i < edges; i++) {
		int x = Find(v[i].a);
		int y = Find(v[i].b);
		//printf ("IN MST x = %d y = %d\n", x, y);
		if (x == y) continue;
		//printf ("IN MST a = %d b = %d\n", v[i].a, v[i].b);
		par[x] = y;
		adj[v[i].a].pb({v[i].b, i});
		adj[v[i].b].pb({v[i].a, i});
	}
	return;
}

void dfs (int u, int p) {
	//printf (">> %d %d \n", u, p);
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i].X;
		if (v != p) {
			nadj[v].pb({u, adj[u][i].Y});
			dfs (v, u);
		}
	}
	return;
}

vector <int> ans[SZ];
int now;
bool flag[SZ*SZ];

void dfs2 (int u, int p, int goal) {
	ans[now].pb(u);
	if (u == goal) return;
	for (int i = 0; i < sz(nadj[u]); i++) {
		int v = nadj[u][i].X;
		if (v != p) {
			flag[nadj[u][i].Y] = 1;
			dfs2(v, u, goal);
		}
	}
	return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
        //freopen("2.txt", "w", stdout);
    #endif

	int n;
	int cs = 0;
	
	while (scanf("%d", &n) == 1 && n != -1) {
		int goal, edges;
		scanf("%d %d", &goal, &edges);

		for (int i = 1; i <= n; i++) {
			par[i] = i;
			adj[i].clear();
			nadj[i].clear();
			ans[i].clear();
		}
		
		for (int i = 0; i < edges; i++) {
			int a, b, c;
			scanf("%d %d %d", &v[i].a, &v[i].b, &v[i].c);
			//v[i].a = min(a, b);
			//v[i].b = max(a, b);
			flag[i] = 0;
		}	

		int nj;
		scanf("%d", &nj);

		for (int i = 0; i < nj; i++) {
			scanf("%d", &judges[i]);
		}

		sort (v, v + edges, comp);		

		MST(edges);
		dfs(goal, -1);

		for (int i = 0; i < nj; i++) {
			now = judges[i];
			dfs2 (judges[i], -1, goal);
		}

		int sum = 0;
		for (int i = 0; i < edges; i++) {
			if (flag[i] == 1) {
				sum += v[i].c;
			}
		}

		printf("Case %d: distance = %d\n", ++cs, sum);
		for (int i = 0; i < nj; i++) {
			printf ("   %d", ans[judges[i]][0]);
			for (int j = 1; j < sz(ans[judges[i]]); j++) {
				printf ("-%d", ans[judges[i]][j]);
			}
			printf("\n");
		}
		printf("\n");
	}	

    return 0;
}






