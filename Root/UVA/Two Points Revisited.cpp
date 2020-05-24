#include "stdio.h"

int main() {
    int test=0, t, i, x1, x2, y1, y2, tmp;

    t = 0;
    i = getchar_unlocked();
    while (i < '0' || i > '9')
        i = getchar_unlocked();
    while (i >= '0' && i <= '9') {
        t = (t << 3) + (t << 1) + i - '0';
        i = getchar_unlocked();
    }

    while(t--) {
        x1 = 0;
        i = getchar_unlocked();
        while (i < '0' || i > '9')
            i = getchar_unlocked();
        while (i >= '0' && i <= '9') {
            x1 = (x1 << 3) + (x1 << 1) + i - '0';
            i = getchar_unlocked();
        }

        y1 = 0;
        i = getchar_unlocked();
        while (i < '0' || i > '9')
            i = getchar_unlocked();
        while (i >= '0' && i <= '9') {
            y1 = (y1 << 3) + (y1 << 1) + i - '0';
            i = getchar_unlocked();
        }

        x2 = 0;
        i = getchar_unlocked();
        while (i < '0' || i > '9')
            i = getchar_unlocked();
        while (i >= '0' && i <= '9') {
            x2 = (x2 << 3) + (x2 << 1) + i - '0';
            i = getchar_unlocked();
        }

        y2 = 0;
        i = getchar_unlocked();
        while (i < '0' || i > '9')
            i = getchar_unlocked();
        while (i >= '0' && i <= '9') {
            y2 = (y2 << 3) + (y2 << 1) + i - '0';
            i = getchar_unlocked();
        }

        if(y1 > y2) tmp = y1;
        else tmp = y2;

        printf("Case %d: %d %d %d %d\n",++test,tmp-y1,x1,tmp-y2,x2);
    }

    return 0;
}
