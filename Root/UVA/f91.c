#include <stdio.h>

inline void inp(long long &n) {
    n = 0;
    int ch = getchar_unlocked();int sign = 1;
    while (ch < '0' || ch > '9') {if (ch == '-') sign = -1; ch = getchar_unlocked();}
    while (ch >= '0' && ch <= '9')
            n = (n << 3) + (n << 1) + ch -'0', ch = getchar_unlocked();
    n = n * sign;
}

int main() {
    long long int n;
    while(true)
    {
        inp(n);
        if (n == 0)
            break;
        else if (n > 100)
            printf("f91(%lld) = %lld\n", n, n - 10);
        else
            printf("f91(%lld) = 91\n", n);
    }
    return 0;
}
