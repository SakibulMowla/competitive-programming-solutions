#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

#define SZ 500010

ll M[SZ], C[SZ]; //y=mx+c we need only m(slope) and c(constant)
ll dp[SZ], sum[SZ], a[SZ];

bool bad (int l1, int l2, int l3) {
    return (C[l3]-C[l1]) * (M[l1]-M[l2]) <= (C[l2]-C[l1]) * (M[l1]-M[l3]);
//query x values is non-decreasing (reverse(> sign) for vice verse)
}

//Adding should be done serially. If we want minimum y coordinate(value) then
//maximum valued m should be inserted first and if we want maximum y
//coordinate(value) then minimum valued m should be inserted first
void add (ll m, ll c, int &last) {
    M[last] = m;
    C[last++] = c;
    while (last >= 3 && bad(last-3, last-2, last-1)) {
        M[last-2] = M[last-1];
        C[last-2] = C[last-1];
        last--;
    }
}

//Returns the minimum y-coordinate of any intersection between a given vertical
//This can only be applied if the query of vertical line(x) is already sorted

long long query (ll x, int &pointer, int last) {
    if (pointer >= last) pointer = last - 1;
    //non-decreasing
    while ((pointer < last - 1) && M[pointer + 1] * x + C[pointer + 1] <= M[pointer] * x + C[pointer]) // Min Value wanted... (reverse(> sign) for max value)
        pointer++;
    return M[pointer] * x + C[pointer];
}

int main() {
    ll n, m;
    while (scanf("%lld %lld", &n, &m) == 2) {
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            sum[i] = sum[i-1] + a[i];
        }

        int last = 1, pointer = 1;

        for (int i = 1; i <= n; i++) {
            dp[i] = query(sum[i], pointer, last) + (sum[i] * sum[i]) + m;
            add(-2LL * sum[i], dp[i] + (sum[i] * sum[i]), last);
        }

        printf("%lld\n", dp[n]);
    }

    return 0;
}
