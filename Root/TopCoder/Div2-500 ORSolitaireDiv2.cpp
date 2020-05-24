//ACed

#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

class ORSolitaireDiv2 {
public:
	int getMinimum(vector <int> numbers, int goal) {
		int i, j, k, ans;
		int cnt[110];

		mem(cnt, 0);
		k = sz(numbers);

		REP(i, k){
            if((numbers[i]|goal) == goal){
                REP(j, 31)
                    if(numbers[i]&(1<<j))
                        cnt[j]++;
            }
		}

		ans = 100;

		REP(i, 31){
            if(goal&(1<<i))
                ans = min(ans, cnt[i]);
		}

		return ans;
	}
};
