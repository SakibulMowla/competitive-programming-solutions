#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  3010

ll tym[SZ];

struct data {
	ll a, b;
	data (ll c, ll d) {
		a = c, b = d;
	}
	bool operator < (const data& p) const {
        return a < p.a;
    }
};

ll D;

bool f (int n, ll mid) {
	queue <int> q;
	for (int i = 1; i < n; i++) {
		q.push(i);
	}		
	
	int cnt = 0;
	int need = n - 1;
	priority_queue <data> pq;
	
	pq.push({0, 0}); 
	
	for (int i = 0; i < n; i++) {
		//cout << ">> " << i << endl;
		data p = pq.top(); pq.pop();
		if (p.a + tym[cnt] > mid) {
			return false;
		}
		
		cnt++;
		
		int abl = min((ll)need, mid - (p.a + tym[cnt]));
		need -= abl;
		
		for (int j = 0; j < abl; j++) {
			pq.push({p.a + D, q.front()});
			q.pop();
		}
	}
	
	return (cnt == n);
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        ll d;
        cin >> n >> d;
        D = d;

        for (int i = 0; i < n; i++) {
            cin >> tym[i];
        }

        sort(tym, tym + n);
        
        ll lo = 1;
        ll hi = 1E12;
        ll ans;
        
        while (lo <= hi) {
        	ll mid = (lo + hi) >> 1LL;
        	if (f(n, mid)) {
        		ans = mid;
        		hi = mid - 1LL;	
        	} else {
        		lo = mid + 1LL;
        	}
        }
        
        cout << ans << endl;
    }

    return 0;
}







