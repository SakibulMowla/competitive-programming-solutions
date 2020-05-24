#include <bits/stdc++.h>
using namespace  std;
typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1000000007LL;

#define SZ  110


class NarrowPassage2 {
public:
	int count(vector <int> size, int maxSizeSum) {
		ll ans = 1LL;

		while(sz(size)) {
            int pos = min_element(size.begin(), size.end()) - size.begin();

            int l = pos;
            while(l-1 >=0 && size[l-1]+size[pos] <= maxSizeSum) l--;

            int r = pos;
            while(r+1 < sz(size) && size[r+1]+size[pos] <= maxSizeSum) r++;

            ans = (ans * (r-l+1LL)) %  mod;
            size.erase(size.begin()+pos);
		}

		return ans;
	}
};
