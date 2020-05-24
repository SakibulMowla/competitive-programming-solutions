//ACed

#include <bits/stdc++.h>
using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define SZ 1010

class MiniatureDachshund {
public:
	int maxMikan(vector <int> mikan, int weight) {
		int i, k, cnt = 0;

		k = sz(mikan);

		sort(mikan.begin(), mikan.end());

		REP(i, k){
            if(weight+mikan[i] <= 5000)
                cnt++, weight+=mikan[i];
            else
                break;
		}

		return cnt;
	}
};
