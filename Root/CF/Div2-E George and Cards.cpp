#include <bits/stdc++.h>

using namespace  std;


#define clr(a) (a.clear())
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)


#define SZ  1000010


int arr[SZ], sustain[SZ], pos[SZ];
int alive[SZ];
int N;

void update(int indx, int val) {
    while(indx <= N) {
        alive[indx] += val;
        indx += (indx & -indx);
    }
}


int query(int indx) {
    int ret = 0;
    while(indx > 0) {
        ret += alive[indx];
        indx -= (indx & -indx);
    }
    return ret;
}


set <int> ms;
set <int>::iterator it;


int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif


    int n, k, i, j, l, r;
    long long ans;

    while(scanf("%d %d",&n,&k) == 2) {
//        memset(sustain, 0, sizeof(int)*(n+10));
//        memset(alive, 0, sizeof(int)*(n+10));
//        clr(ms);
        N = n;

        REP1(i, 1, n) {
            scanf("%d",&arr[i]);
            pos[ arr[i] ] = i;
            update(i, 1);
        }
        REP1(i, 1, k) {
            scanf("%d",&j);
            sustain[j] = 1;
        }

        ms.insert(0);
        ms.insert(n+1);

        ans = 0;
        REP1(i, 1, n) {
            if(sustain[i]) {
                ms.insert(pos[i]);
                continue;
            }

            it = ms.upper_bound(pos[i]);
            r = (*it) - 1;
            it = --ms.upper_bound(pos[i]);
            l = *it;

            ans += query(r) - query(l);
            update(pos[i], -1);
        }

        printf("%I64d\n",ans);
    }


    return 0;
}
