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



class ORSolitaire {
public:
	int getMinimum(vector <int> numbers, int goal) {
		ll i, j, k, ans, cnt;

		vector <ll> arr;

		k = sz(numbers);

		REP(i, k) {
            REP(j, 33) {
                if( ((ll)( (ll)goal&(1LL<<j)  ) == 0) &&  ((ll)( (ll)numbers[i]&(1LL<<j)  ) != 0)  )
                    break;
            }
            if(j == 33)
                arr.pb(numbers[i]);
		}

		k = sz(arr);
		j = 0;

		REP(i, k) {
            j = j | arr[i];
		}

		if(j != goal)
            return 0;

        ans = 1e12;

        REP(i, 33) {
            cnt = 0;
            if( (ll)( (ll)goal&(1LL<<i)  ) != 0 ) {
                REP(j, k) {
                    if((ll)( (ll)arr[j]&(1LL<<i)  ) != 0)
                        cnt++;
                    }
                ans = min(ans, cnt);
            }
        }

        return (int)ans;
	}
};

