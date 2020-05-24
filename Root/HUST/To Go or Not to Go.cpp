#include <stdio.h>

using namespace  std;

typedef long long ll;

#define mem(a,b) memset(a, b, sizeof(a))

#define SZ 32

int len;
int num[SZ];

void prep (int n) {
    len = 0;
    while (n) {
        num[len++] = n % 2;
        n /= 2;
    }
    return;
}

ll dp1[SZ][2], dp2[SZ][2];
int col1[SZ][2], col2[SZ][2];
int now1, now2;

ll solve2 (int pos, int flag) {
    if(pos == -1) return 1LL;
    ll &ret = dp2[pos][flag];
    if(col2[pos][flag] == now2) return ret;
    col2[pos][flag] = now2;

    ret = 0LL;
    int lim = flag ? num[pos] : 1;
    for (int i = 0; i <= lim; i++) {
        int nflag = 0;
        if(flag == 1 && i == lim) nflag = 1;
        ret += solve2(pos-1, nflag);
    }

    return ret;
}

ll solve1 (int pos, int flag) {
    if(pos == -1) return 0LL;
    ll &ret = dp1[pos][flag];
    if(col1[pos][flag] == now1) return ret;
    col1[pos][flag] = now1;

    ret = 0LL;
    int lim = flag ? num[pos] : 1;
    for (int i = 0; i <= lim; i++) {
        int nflag = 0;
        if(flag == 1 && i == lim) nflag = 1;
        ret += solve1(pos-1, nflag);
        if(i == 1) ret += solve2(pos-1, nflag);
    }

    return ret;
}

double solve (int n) {
    if(n <= 0) return 0.0;
    if(n == 1) return 1.0;
    double ans = 0.0;
    prep(n);
    for (int i = 0; i < 31; i++)
        num[i] = 1;
    now1++, now2++;
    for (int i = 1; i < len; i++) {
        if(i == 1) ans += 1.0;
        else ans += ((double)solve1(i-2, 1)+(double)solve2(i-2, 1)) / (double)i;
    }
    prep(n);
    now1++, now2++;
    ans += ((double)solve1(len-2, 1)+ (double)solve2(len-2, 1)) / (double)len;
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int cs = 0; cs < n; cs++) {
        int a, b;
        scanf("%d %d", &a, &b);
        double ans = (solve(b) - solve(a-1)) / (double)(b-a+1);
        printf("%.6lf\n", ans);
    }

    return 0;
}
