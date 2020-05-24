#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "string"
#include "vector"
#include "set"
#include "stack"
#include "queue"
#include "iostream"
#include "algorithm"
#include "assert.h"
#include "map"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define MP(a, b) make_pair(a, b)
#define clr(a) (a.clear())
#define sz(a) ((int)a.size())
#define REP(i, n) for(i=0;i<(int)n;i++)
#define REP1(i, a, b) for(i=a;i<=(int)b;i++)
#define REP2(i, a, b) for(i=a;i>=(int)b;i--)
#define SZ 1010
struct data{
    double a, b;
};
bool comp(data p, data q){
    if(p.a == q.a)
        return p.b < q.b;
    return p.a < q.a;
}
data arr[10];
char ss[10];
bool ok(double mid, int n){
    int indx, i, j, k, m;
    double last;
    REP1(i, 1, n){
        indx = ss[i]-'0';
        if(i == 1){
            last = arr[indx].a;
            continue;
        }
        if(arr[indx].b >= last + mid){
            last = max(arr[indx].a, last+mid);
        }
        else
            return false;
    }
    return true;
}
bool chk(double mid, int n){
    int i;
    REP1(i, 1, n) ss[i] = i+'0';
    ss[0] = 'a';
    ss[i] = '\0';
    do{
        if(ok(mid, n)){
//            printf("ss = %s\n",ss);
            return true;
        }
    }while(next_permutation(ss+1, ss+1+n));
    return false;
}
int main(){
//    freopen("1.txt","r",stdin);
    int i, j, k, n, m, lo, hi, mid, ans, test=0;
    while(scanf("%d",&n) == 1 && n){
        hi = 0;
        REP1(i, 1, n){
            scanf("%lf %lf",&arr[i].a,&arr[i].b);
            arr[i].a *= 60;
            arr[i].b *= 60;
            hi = max(hi, (int)arr[i].b);
        }
//        sort(arr+1, arr+n+1, comp);
        lo = 0;
        while(lo <= hi){
            mid = (lo + hi) / 2;
            if(chk(mid, n)){
                ans = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        if(chk(ans+0.5, n))
            ans++;
        printf("Case %d: %d:%02d\n",++test, ans/60, ans%60);
    }
    return 0;
}
