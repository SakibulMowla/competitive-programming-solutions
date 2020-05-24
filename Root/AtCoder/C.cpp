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


#define SZ 200010

const pii inf = {2000000000, 2000000000}; // a large value as infinity
const pii ninf = {-2000000000, -2000000000}; // a large value as infinity

int n; // the number of items in the sequence
pii Sequence[SZ]; // the sequence of integers
pii L[SZ]; // L[] as described in the algorithm
pii I[SZ]; // I[] as described in the algorithm
int type;

bool comp1(pii a, pii b) {

}

bool comp2(pii a, pii b) {

}

bool comp(pii a, pii b) {
    if (type == 1) return comp1(a, b);
    else return comp2(a, b)
}

int LisNlogK() { // which runs the NlogK LIS algorithm
    int i; // auxilary variable for iteration

    I[0] = -inf; // I[0] = -infinite
    for( i = 1; i <= n; i++ ) // observe that i <= n are given
        I[i] = inf; // I[1 to n] = infinite

    int LisLength = 0; // keeps the maximum position where a data is inserted

    for( i = 0; i < n; i++ ) { // iterate left to right
        int low, high, mid; // variables to perform binary search
        low = 0; // minimum position where we to put data in I[]
        high = LisLength; // the maximum position

        while( low <= high ) { // binary search to find the correct position
            mid = ( low + high ) / 2;
            if( I[mid] < Sequence[i] )
                low = mid + 1;
            else
                high = mid - 1;
        }
        // observe the binary search carefully, when the binary search ends
        // low > high and we put our item in I[low]
        I[low] = Sequence[i];
        if( LisLength < low ) // LisLength contains the maximum position
            LisLength = low;
    }

    return LisLength; // return the result
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int mnx = min(x1, x2);
    int mny = min(y1, y2);
    int mxx = max(x1, x2);
    int mxy = max(y1, y2);

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if ()
    }

    return 0;
}




