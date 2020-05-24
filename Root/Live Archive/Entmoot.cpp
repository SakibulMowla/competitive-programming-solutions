#include "stdio.h"
#include "math.h"
#include "string.h"
#include "string"
#include "iostream"
#include "algorithm"
#include "set"
#include "queue"
#include "map"
#include "stdlib.h"
#include "assert.h"
#include "deque"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double inf = 1e16;
const int mod = 1;

#define REP(i, n) for(i=0;i<(int)n;i++)
#define REP1(i, a, b) for(i=(int)a;i<=(int)b;i++)
#define REP2(i, a, b) for(i=(int)a;i>=(int)b;i--)
#define clr(a) a.clear()
#define sz(a) (int)a.size()
#define MP(a, b) make_pair(a, b)
#define mem(a, b) memset(a, b, sizeof(a))

#define SZ 65

struct data{
    double x, y, s;
};

data arr[SZ];
int n;

double minimx, minimy, maximx, maximy;

double ok(double xx, double yy){
    int i;
    double d = 0, tmp;

    REP(i, n){
        tmp = (arr[i].x-xx)*(arr[i].x-xx) + (arr[i].y-yy)*(arr[i].y-yy);
        tmp = sqrt(tmp);
        tmp = tmp / arr[i].s;
        d = max(d, tmp);
    }

    return d;
}


double ff(double xx){
    int i;
    double lo, hi, m1, m2, ans1, ans2, ans;

    lo = minimy;
    hi = maximy;
    ans = inf;

    REP(i, 50){
        m1 = (2.0*lo+hi)/3.0;
        m2 = (lo+2.0*hi)/3.0;

        ans1 = ok(xx, m1);
        ans2 = ok(xx, m2);

        ans = min(ans, min(ans1, ans2));

        if(ans1 >= ans2)  lo = m1;
        else hi = m2;
    }

    return ans;
}

double f(){
    int i;
    double lo, hi, m1, m2, ans1, ans2, ans;

    lo = minimx;
    hi = maximx;
    ans = inf;

    REP(i, 50){
        m1 = (2.0*lo+hi)/3.0;
        m2 = (lo+2.0*hi)/3.0;

        ans1 = ff(m1);
        ans2 = ff(m2);

        ans = min(ans1, ans2);

        if(ans1 >= ans2)  lo = m1;
        else hi = m2;
    }

    return ans;
}


int main(){
//    freopen("1.txt","r",stdin);

    int t, i;
    double lo, hi, m1, m2, mid, ans1, ans2, ans;

    scanf("%d",&t);

    while(t--){
        minimx = inf;
        minimy = inf;
        maximx = -inf;
        maximy = -inf;

        scanf("%d",&n);
        REP(i, n) {
            scanf("%lf %lf %lf",&arr[i].x,&arr[i].y,&arr[i].s);
            minimx = min(minimx, arr[i].x);
            maximx = max(maximx, arr[i].x);
            minimy = min(minimy, arr[i].y);
            maximy = max(maximy, arr[i].y);
        }

        printf("%.10lf\n",f());
    }


    return 0;
}




