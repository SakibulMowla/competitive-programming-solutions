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
const int inf = 1e9;
const ll mod = 1LL;

#define SZ  1010
#define SZ1 32

int depth[SZ];
int quantity[SZ];
pii dp[SZ][SZ1];
int mark[SZ][SZ1];
int w, N;

pii solve(int tym, int indx){
    pii &ret = dp[tym][indx];
    if(ret.X != -1) return ret;
    if(indx == N) return MP(0, 0);

    pii tmp = MP(-inf, 0);

    ret = solve(tym, indx+1);

    if(tym-3*w*depth[indx] >= 0){
        tmp = solve(tym-3*w*depth[indx], indx+1);
        tmp.X += quantity[indx];
        tmp.Y += 1;
    }

    if(tmp.X > ret.X)
        ret = tmp, mark[tym][indx] = 1;

    return ret;
}

void path_print(int gain, int tym, int indx){
    if(indx == N) return;
    if(dp[tym][indx].X == gain && mark[tym][indx] == 1){
        printf("%d %d\n",depth[indx],quantity[indx]);
        return path_print(gain-quantity[indx], tym-3*w*depth[indx], indx+1);
    }
    return path_print(gain, tym, indx+1);
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t, i, j;
    bool blank = false;

    while(scanf("%d %d",&t,&w) == 2){
        scanf("%d",&N);

        if(blank) puts("");
        else blank = true;

        REP(i, N) {
            RD(depth[i]);
            RD(quantity[i]);
        }

        REP(i, t+2) REP(j, N+2) dp[i][j].X = -1, mark[i][j] = 0;

        PR(i = solve(t, 0).X);
        PR(solve(t, 0).Y);
        path_print(i, t, 0);
    }


    return 0;
}













