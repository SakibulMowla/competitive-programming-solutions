#include <bits/stdc++.h>

inline void inp(long long &n) {
    n = 0;
    int ch = getchar_unlocked();
    while (ch < '0' || ch > '9') {
        ch = getchar_unlocked();
    }
    while (ch >= '0' && ch <= '9') {
        n = (n << 3LL) + (n << 1LL) + (ch-'0');
        ch = getchar_unlocked();
    }
}

int main() {
    long long f[65], n = 1LL;
    for (int i = 0; i < 64; i++) {
        f[i] = n - 1LL;
        n <<= 1LL;
    }


    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        long long l, r;
        inp(l); inp(r);

        int i;
        for (i = 63; i >= 0; i--) {
            if (((l >> i) & 1) != ((r >> i) & 1)) {
                break;
            }
        }

        if (i != -1) {
            r |= f[i+1];
            l &= ~f[i+1];
        }

//        for (; i >= 0; i--) {
//            r |= 1LL << i;
//            l &= ~(1LL << i);
//        }

        printf("Case %d: %lld %lld\n", cs + 1, r, l);
    }

    return 0;
}
