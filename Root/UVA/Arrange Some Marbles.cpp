#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>
#include <assert.h>

//#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

void RD(int &x){scanf("%d",&x);}
void RD(ll &x){scanf("%lld",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}
void RD(char *s){scanf("%s",s);}
void RD(char &s){scanf("%c",&s);}
void RD(string &s){cin>>s;}

void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}
void PR(ll x) {printf("%lld\n",x);}
void PR(char x) {printf("%c\n",x);}
void PR(char *x) {printf("%s\n",x);}
void PR(string x) {cout<<x<<endl;}

//inline void inp( int &n ){
//    n=0;
//    int ch=getchar_unlocked();int sign=1;
//    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
//    while(  ch >= '0' && ch <= '9' )
//            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
//    n=n*sign;
//}


#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1LL;

#define SZ  100010

int dp[8][8][8][8][4][4][4][4];

int solve(int cnt1, int cnt2, int cnt3, int cnt4, int precol, int precnt, int fstcol, int fstcnt){
    if(cnt1+cnt2+cnt3+cnt4 == 0){
        return ((precol!=fstcol && precnt!=fstcnt) || (fstcnt == 0));
    }

    int &ret = dp[cnt1][cnt2][cnt3][cnt4][precol][precnt][fstcol][fstcnt];
    if(ret != -1) return ret;

    int i, j, arr[5], tmp1, tmp2, help[5];

    ret = 0LL;
    arr[0] = cnt1;
    arr[1] = cnt2;
    arr[2] = cnt3;
    arr[3] = cnt4;

    for(i=0;i<=3;i++) if(fstcnt == 0 || i != precol) {
        for(j=1; j<=arr[i] && j<=3; j++) if(fstcnt == 0 || j != precnt) {
            if(fstcnt == 0) tmp1 = i, tmp2 =  j;
            else tmp1 = fstcol, tmp2 = fstcnt;
            help[0] = arr[0], help[1] = arr[1], help[2] = arr[2], help[3] = arr[3];
            if(i == 0) help[0] -= j;
            else if(i == 1) help[1] -= j;
            else if(i == 2) help[2] -= j;
            else if(i == 3) help[3] -= j;
            ret += solve(help[0], help[1], help[2], help[3], i, j, tmp1, tmp2);
        }
    }

    return ret;
}

//688022064
//688022064

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int arr[6], test, n, i;

    RD(test);
    mem(dp, -1);

    while(test--){
        arr[0] = arr[1] = arr[2] = arr[3] = 0;
        RD(n);
        REP(i, n) RD(arr[i]);
        PR(solve(arr[0], arr[1], arr[2], arr[3], 0, 0, 0, 0));
    }


    return 0;
}






