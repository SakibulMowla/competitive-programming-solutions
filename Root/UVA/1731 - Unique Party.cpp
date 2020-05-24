#include <stdio.h>
#include <algorithm>

using namespace std;

#define SZ 252

int a[SZ][SZ];
int sum[SZ][SZ];
int tmp[SZ];
int best[SZ];

inline void inp (int &n) {
    n = 0;
    int ch = getchar_unlocked();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
}

int solve (int r, int c, int h) {
    for (int i  = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            sum[i][j] = (a[i][j] >= h? 1: -1) + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }

    int ans = 0;
    for (int r1 = 1; r1 <= r; r1++) {
        for (int r2 = r1; r2 <= r; r2++) if ((r2 - r1 + 1) * c > ans) {
            best[c + 1] = -90000;
            for (int c2 = c; c2 >= 1; c2--) {
                tmp[c2] = sum[r2][c2] - sum[r1 - 1][c2];
                best[c2] = max(tmp[c2], best[c2 + 1]);
            }

            for (int l = 1, r = 1; l <= c; l++) {
                r = max(l, r);
                while (r + 1 <= c && best[r + 1] - tmp[l - 1] >= 0) r++;
                if (best[r] - tmp[l-1] >= 0) ans = max(ans, (r - l + 1) * (r2 - r1 + 1));
            }
        }
    }

    return ans;
}

int main() {
    int t;
//    scanf("%d", &t);
    inp(t);

    for (int cs = 0; cs < t; cs++) {
        int r, c;
//        scanf("%d %d", &r, &c);
        inp(r); inp(c);

        for (int i  = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
//                scanf("%d", &a[i][j]);
                inp(a[i][j]);
            }
        }

        printf("Case %d:\n", cs + 1);

        int q;
//        scanf("%d", &q);
        inp(q);

        for (int i = 0; i < q; i++) {
            int h;
//            scanf("%d", &h);
            inp(h);
            printf("%d\n", solve(r, c, h));
        }
    }

    return 0;
}


