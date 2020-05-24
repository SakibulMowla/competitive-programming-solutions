//ACed

#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define sz(x) (int)x.size()

class TheShuttles {
public:
	int getLeastCost(vector <int> cnt, int base, int seat) {
		int i, j, k, koyta, ans;
		k = sz(cnt);
		ans = 1e9;
		for(i=1;i<=100;i++){
            koyta = 0;
            for(j=0;j<k;j++)
                koyta += cnt[j]/i + (bool)(cnt[j]%i);
            ans = min(ans, koyta*(base+seat*i));
		}

		return ans;
	}
};
