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
void RD(ll &x){scanf("%I64d",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(ll &x,ll &y){scanf("%I64d%I64d",&x,&y);}

void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}
void PR(ll x) {printf("%I64d\n",x);}

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

#define SZ 1910

ll dp[20][2][20][SZ];
int col[20][2][20][SZ];
int arr[20];
int len;
int now_col;

ll digit_dp(int indx, bool flag, int pivot, int val){
    if(indx == len) return (ll)(val == 0);
    if(val < 0) return 0LL;

    ll &ret = dp[indx][flag][pivot][val];
    if(col[indx][flag][pivot][val] == now_col) return ret;
    col[indx][flag][pivot][val] = now_col;

    int i, lim;
    bool nflag;

    ret = 0LL;
    lim = flag ? arr[indx] : 9;

    for(i=0; i<=lim; i++){
        if(flag && i==lim) nflag = 1;
        else nflag = 0;
        ret += digit_dp(indx+1, nflag, pivot, val + i * (pivot - indx));
    }

    return ret;
}

ll solve(ll n){
    if(n < 0) return 0LL;

    len = 0;
    while(n){
        arr[len++] = n%10;
        n /= 10;
    }
    reverse(arr, arr+len);

    ll ans = 0LL;
    int i;

    now_col++;
//    mem(dp, -1);
    for(i=0; i<len; i++)
        ans += digit_dp(0, 1, i, 0);

    return ans - len + 1; /// 0, 00, 000, 0000, ... etc. are all the same and they are counted
                          /// for more than once, so this is reducing the extra 0's
}

int main() {
    #if defined JESI
//        freopen("1.txt","r",stdin);
//        freopen("2.txt","w",stdout);
    #endif // defined

    now_col = 0;
    int test;
    ll x, y;

    RD(test);

    while(test--){
        RD(x, y);
        PR(solve(y) - solve(x-1));
    }

    return 0;
}







