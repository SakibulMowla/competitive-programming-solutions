#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define pb push_back
#define sz(a) (int)a.size()

#define SZ 100010

const ll inf = 1;
const ll mod = 1000000007;

/*
1 -> 7
2 -> 2
3 -> 2
4 -> 2
*/

void Mark (int &mask, int digit) {
    if (digit == 1) {
        for (int i = 0; i < 7; i++) {
            if (!(mask & (1 <<i))) {
                mask |= (1 <<i);
                return;
            }
        }
    } else if (digit == 2) {
        for (int i = 7; i < 9; i++) {
            if (!(mask & (1 <<i))) {
                mask |= (1 <<i);
                return;
            }
        }
    } else if (digit == 3) {
        for (int i = 9; i < 11; i++) {
            if (!(mask & (1 <<i))) {
                mask |= (1 <<i);
                return;
            }
        }
    } else if (digit == 4) {
        for (int i = 11; i < 13; i++) {
            if (!(mask & (1 <<i))) {
                mask |= (1 <<i);
                return;
            }
        }
    } else if (digit == 5) {
        mask |= (1 << 13);
    } else if (digit == 6) {
        mask |= (1 << 14);
    } else if (digit == 7) {
        mask |= (1 << 15);
    } else if (digit == 8) {
        mask |= (1 << 16);
    } else if (digit == 9) {
        mask |= (1 << 17);
    } else if (digit == 0) {
        mask |= (1 << 18);
    }
    return;
}

int _find (int mask, int digit) {
    if (digit == 1) {
        for (int i = 0; i < 7; i++) {
            if (mask & (1 <<i)) {
                return (mask & ~(1 << i));
            }
        }
        return -1;
    } else if (digit == 2) {
        for (int i = 7; i < 9; i++) {
            if (mask & (1 <<i)) {
                return (mask & ~(1 << i));
            }
        }
        return -1;
    } else if (digit == 3) {
        for (int i = 9; i < 11; i++) {
            if (mask & (1 <<i)) {
                return (mask & ~(1 << i));
            }
        }
        return -1;
    } else if (digit == 4) {
        for (int i = 11; i < 13; i++) {
            if (mask & (1 <<i)) {
                return (mask & ~(1 << i));
            }
        }
        return -1;
    } else if (digit == 5) {
        if (mask & (1 << 13)) {
            return (mask & ~(1 << 13));
        }
        return -1;
    } else if (digit == 6) {
        if (mask & (1 << 14)) {
            return (mask & ~(1 << 14));
        }
        return -1;
    } else if (digit == 7) {
        if (mask & (1 << 15)) {
            return (mask & ~(1 << 15));
        }
        return -1;
    } else if (digit == 8) {
        if (mask & (1 << 16)) {
            return (mask & ~(1 << 16));
        }
        return -1;
    } else if (digit == 9) {
        if (mask & (1 << 17)) {
            return (mask & ~(1 << 17));
        }
        return -1;
    }
    return -1;
}

int pos[22];

ll dp[(1<<19) + 10];
ll ten[30];
ll fact[20];

ll f (int mask) {
    ll ans = fact[__builtin_popcount(mask)];
    int cnt = 0;
    for (int i = 0; i < 7; i++) {
        if (mask & (1<<i)) {
            cnt++;
        }
    }
    ans /= fact[cnt];
    cnt = 0;
    for (int i = 7; i < 9; i++) {
        if (mask & (1<<i)) {
            cnt++;
        }
    }
    ans /= fact[cnt];
    cnt = 0;
    for (int i = 9; i < 11; i++) {
        if (mask & (1<<i)) {
            cnt++;
        }
    }
    ans /= fact[cnt];
    cnt = 0;
    for (int i = 11; i < 13; i++) {
        if (mask & (1<<i)) {
            cnt++;
        }
    }
    ans /= fact[cnt];
    return ans % mod;
}

ll solve (int poss, int mask) {
    if (mask == 0) return 0;
    if (__builtin_popcount(mask) == 1) {
        for (int i = 0; i < 19; i++) {
            if (mask & (1<<i)) {
                return pos[i];
            }
        }
    }

    ll &ret = dp[mask];
    if (ret != -1) return ret;

    ret = 0;
    if (poss != 0 && (mask & (1 << 18))) ret = solve(poss + 1, mask & ~(1 << 18));

    for (int i = 1; i <= 9; i++) {
        int tmp = _find(mask, i);
        if (tmp != -1) {
            ret = (ret + (((ll)i * ten[__builtin_popcount(tmp)]) % mod * f(tmp)) % mod
                   + solve(poss + 1, tmp)) % mod;
        }
    }

    return ret;
}

void pprint(int n) {
    for (int i = 20; i >= 0; i--) {
        if (n & (1<<i)) printf("1");
        else printf("0");
    }
    printf("\n");
}

int ans[20];

int main () {
    ios::sync_with_stdio(false);

    pos[0] = 1;
    pos[1] = 1;
    pos[2] = 1;
    pos[3] = 1;
    pos[4] = 1;
    pos[5] = 1;
    pos[6] = 1;
    pos[7] = 2;
    pos[8] = 2;
    pos[9] = 3;
    pos[10] = 3;
    pos[11] = 4;
    pos[12] = 4;
    pos[13] = 5;
    pos[14] = 6;
    pos[15] = 7;
    pos[16] = 8;
    pos[17] = 9;
    pos[18] = 0;

    ten[0] = 1;
    for (int i = 1; i < 20; i++) {
        ten[i] = (10LL * ten[i-1]) % mod;
    }
    fact[0] = 1;
    for (int i = 1; i < 20; i++) {
        fact[i] = (ll)i * fact[i-1];
    }

    ans[1] = 1;
    ans[2] = 33;
    ans[3] = 1332;
    ans[4] = 66660;
    ans[5] = 3999960;
    ans[6] = 279999720;
    ans[7] = 399997606;
    ans[8] = 999965735;
    ans[9] = 998387207;
    ans[10] = 565049009;
    ans[11] = 859277330;
    ans[12] = 764790586;
    ans[13] = 560905302;
    ans[14] = 319404197;


    int t;
    scanf("%d", &t);
//    t = 14;

    for (int cs = 0; cs < t; cs++) {
        int n;
        scanf("%d", &n);
//        n = cs + 1;
//
//        int mask = 0;
//        for (int i = 1; i <= n; i++) {
//            int j = i;
//            while (j) {
//                Mark(mask, j % 10);
//                j /= 10;
//            }
//        }
////        pprint(mask);
//        memset(dp, -1, sizeof dp);
//        printf("ans[%d] = %lld;\n",cs + 1, solve(0, mask));
        printf("Case %d: %d\n", cs + 1, ans[n]);
    }

    return 0;
}


