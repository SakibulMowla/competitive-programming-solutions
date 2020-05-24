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

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = sz(nums);
        vector <int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int l = -1, r = -1;
        for (int i = 0; i < n; i++) {
            if (tmp[i] != nums[i]) {
                if (l == -1) l = i, r = i;
                else {
                    l = min(l, i);
                    r = max(r, i);
                }
            }
        }
        return r - l + 1;
    }
};

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    vector <int> nums{1, 1, 1};

    Solution sol;
    cout << sol.findUnsortedSubarray(nums) << endl;

    return 0;
}




