#include "stdio.h"

long long extGcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        int g = extGcd(b, a % b, y, x);
        y -= a / b * x;
        return g;
    }
}

long long modInv(long long a, long long m) {
    long long x, y;
    extGcd(a, m, x, y);
    x %= m;
    while (x < 0) {
        x += m;
    }
    return x;
}

int main() {
    printf("%lld\n",modInv(3, 10));

    return 0;
}
