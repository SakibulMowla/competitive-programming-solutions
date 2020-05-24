#include <bits/stdc++.h>

using namespace  std;

void RD(int &x) {scanf("%d",&x);}
void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)

const int inf = 1e9;

#define SZ 1010

int arr[SZ];

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    int i, n, strt, r, ans, step, mx, mn, now, tmp;

    while(scanf("%d",&n) == 1) {
        REP(i, n) RD(arr[i+1]);
        sort(arr+1, arr+n+1);

        ans = inf;
        REP1(step, 0, 20000){
            mx = -inf;
            mn = inf;
            for(i=1, now=arr[1]; i<=n; i++, now+=step){
                mx = max(mx, arr[i]-now);
                mn = min(mn, arr[i]-now);
            }
            tmp = (mx - mn + 1) / 2;
            if(tmp < ans){
                ans = tmp;
                strt = arr[1] + (mx - tmp);
                r = step;
            }
        }

        PR(ans);
        PR(strt, r);
    }



    return 0;
}




