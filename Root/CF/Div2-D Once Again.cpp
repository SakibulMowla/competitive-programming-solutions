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

const ll mod = 1E9;
const int inf = 2E9;

#define SZ 100010

vector <int> LisNlogK (int n, vector <int>& Sequence) { // which runs the NlogK LIS algorithm
    vector <int> I(n + 1, inf), ans(n, 0);
    I[0] = -inf; // I[0] = -infinite

    int LisLength = 0; // keeps the maximum position where a data is inserted


    for(int i = 0; i < n; i++ ) { // iterate left to right
        int low, high, mid; // variables to perform binary search
        low = 0; // minimum position where we to put data in I[]
        high = LisLength; // the maximum position

        while( low <= high ) { // binary search to find the correct position
            mid = ( low + high ) / 2;
            if( I[mid] <= Sequence[i] )
                low = mid + 1;
            else
                high = mid - 1;
        }
        // observe the binary search carefully, when the binary search ends
        // low > high and we put our item in I[low]
        I[low] = Sequence[i];
        if( LisLength < low ) // LisLength contains the maximum position
            LisLength = low;
        ans[i] = low;
    }

    return ans; // return the result
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n, t;
    cin >> n >> t;

    vector <int> tmp(n), a, cnt(310, 0);
    for (int i = 0; i < n; i++) {
        cin >> tmp[i];
        cnt[tmp[i]]++;
    }

    for (int i = 0; i < n; i++) {
        a.insert(a.end(), tmp.begin(), tmp.end());
    }

    vector <int> b = a;
    reverse(b.begin(), b.end());

    for (int i = 0; i < n * n; i++) {
        b[i] = -b[i];
    }

    if (t <= 2 * n) {
        a.insert(a.end(), a.begin(), a.end());
        vector <int> LISa = LisNlogK(2 * n * n, a);
        cout << *max_element(LISa.begin(), LISa.begin() + (t * n)) << endl;
    } else {
        vector <int> LISa = LisNlogK(n * n, a);
        vector <int> LISb = LisNlogK(n * n, b);
        reverse(LISb.begin(), LISb.end());

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) if (a[j] >= a[i]) {
                for (int k = 0; k < n; k++) if (a[k] >= a[i] && a[k] <= a[j]) {
                    ans = max(ans, LISa[n * (n - 1) + i] + (t - 2 * n) * cnt[a[k]] + LISb[j]);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}





