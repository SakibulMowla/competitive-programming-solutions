#include "stdio.h"

using namespace  std;

typedef long long ll;

ll Zeroes (ll n) {
    ll cnt = 0LL;
    while (n >= 5LL) {
        cnt += n / 5LL;
        n /= 5LL;
    }
    return cnt;
}

int main() {
    ll a, b;

//    a = 1LL;
   // b = 9E18;
   // printf("%lld %lld\n", b, Zeroes(b));
//    printf("%lld\n", a);

    while (scanf("%lld %lld", &a, &b) == 2) {
        if (a == 0LL && b == 0LL) break;
        printf("%lld\n", (b / 5LL) - (a / 5LL) + 1);
    }

    return 0;
}






