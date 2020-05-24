#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define pb push_back
#define sz(a) (int)a.size()

#define SZ 1000010

const ll inf = 1;
const ll mod = 1;

vector <int> prime;
bool arr[SZ];

void sieve () {
    int lim = sqrt(SZ);
    prime.pb(2);
    for (int i = 3; i <= lim; i += 2) {
        if (!arr[i]) {
            for (int j = i * i; j < SZ; j += i + i) {
                arr[j] = 1;
            }
        }
    }
    for (int i = 3; i < SZ; i += 2) {
        if (!arr[i]) {
            prime.pb(i);
        }
    }
//    for (int i = 0; i < 25; i++) cout << prime[i] << ' ';
    return;
}

int NOD (int n) {
    int ans = 1;
    for (int i = 0; i < sz(prime) && (ll)prime[i] * (ll)prime[i] <= n; i++) {
        if (n % prime[i] == 0) {
            int cnt = 1;
            while (n % prime[i] == 0) {
                n /= prime[i];
                cnt++;
            }
            ans *= cnt;
        }
    }
    if (n != 1) {
        ans *= 2;
    }
    return ans;
}

int nod[SZ];
int p[300];

int main () {
    ios::sync_with_stdio(false);

    sieve();

    for (int i = 1; i <= 1000000; i++) {
        nod[i] = NOD(i);
    }

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int l, r;
        scanf("%d %d", &l, &r);

        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
        }

        int ans = l, mx = -1;
        for (int i = l; i <= r; i++) {
            if (p[nod[i]] > mx) {
                ans = i;
                mx = p[nod[i]];
            }
        }

        printf("Case %d: %d\n", cs + 1, ans);
    }

    return 0;
}


