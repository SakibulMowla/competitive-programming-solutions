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

#define SZ 1010

struct data {
	int ppl, tym;
};

bool comp (data p, data q) {
	return p.ppl > q.ppl;
}

data workshops[SZ], rooms[SZ];
multiset <int> ms;

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
        freopen("2.txt", "w", stdout);
    #endif

	int cs = 0;
	int w;
	
	while (scanf("%d", &w) == 1 && w) {
		for (int i = 0; i < w; i++) {
			scanf("%d %d", &workshops[i].ppl, &workshops[i].tym);
		}
		int r;
		scanf("%d", &r);
		for (int i = 0; i < r; i++) {
			int a, b;
			scanf("%d %d:%d", &rooms[i].ppl, &a, &b);
			rooms[i].tym = a * 60 + b - 14 * 60;
		}

		sort (workshops, workshops + w, comp);
		sort (rooms, rooms + r, comp);

		clr(ms);
		int tent = 0, sum = 0;

		for (int i = 0, j = 0; i < w; i++) {
			for (; j < r; j++) {
				if (rooms[j].ppl < workshops[i].ppl) {
					break;
				}
				ms.insert(rooms[j].tym);
			}
			auto it = ms.lower_bound(workshops[i].tym);
			if (it == ms.end()) {
				tent++;
				sum += workshops[i].ppl;
			} else {
				ms.erase(it);
			}
		}

		printf("Trial %d: %d %d\n\n", ++cs, tent, sum);
	}

    return 0;
}






