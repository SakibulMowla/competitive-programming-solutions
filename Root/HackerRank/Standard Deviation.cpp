#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
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

#define SZ 100010

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
	int n1 = A.size(), n2 = B.size(), n3 = C.size();
	int mx = max(A[0], max(B[0], C[0]));
	int mn = min(A[0], min(B[0], C[0]));
	int ans = mx - mn;
	for (int i = 0, j = 0, k = 0; i != n1 - 1 || j != n2 - 1 || k != n3 - 1; )	{
		if (i + 1 < n1 && A[i + 1] <= mx) i++;
		else if (j + 1 < n2 && B[j + 1] <= mx) j++;
		else if (k + 1 < n3 && C[k + 1] <= mx) k++;
		else {
			int next1 = (i + 1 < n1 ? max(A[i + 1], max(B[j], C[k])) - min(A[i + 1], min(B[j], C[k])) : numeric_limits<int>max());
			int next2 = (j + 1 < n2 ? max(A[i], max(B[j + 1], C[k])) - min(A[i], min(B[j + 1], C[k])) : numeric_limits<int>max());
			int next1 = (k + 1 < n3 ? max(A[i], max(B[j], C[k + 1])) - min(A[i], min(B[j], C[k + 1])) : numeric_limits<int>max());
			if (next1 <= next2 && next1 <= next3) i++;
			else if (next2 <= next1 && next2 <= next3) j++;
			else k++;
		}
		mx = max(A[i], max(B[j], C[k]));
		mn = min(A[i], min(B[j], C[k]));
		ans = min(ans, mx - mn);
	}
	return ans;
}


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <int> a(n);
    int sum = 0;

    for (auto &x: a) cin >> x, sum += x;

    double mean = 1.0 * sum / n;
	double sqr_sum = 0;

	for (auto x: a) {
		sqr_sum += (x - mean) * (x - mean);
	}

	cout << fixed << setprecision(1) << sqrt(sqr_sum / n) << endl;

    return 0;
}






