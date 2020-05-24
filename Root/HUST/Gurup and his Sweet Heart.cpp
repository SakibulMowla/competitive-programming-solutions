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

inline ll BigMod(ll B,ll P){
    ll R=1;
    while(P>0) {
          if(P%2==1){
                R=(R*B);
            }
        P/=2;
        B=(B*B);
    }
    return R;
}

inline ll fun(ll n, ll koybar, ll div){

    while(koybar--){
        n /= div;
        if(n == 0) return n;
    }

    return n;
}


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;

    ll n, i, j, k, lo, hi, mid;
    double d, d1, d2;
    bool f;

    scanf("%d",&t);

    while(t--){
        f = 0;

        scanf("%lld",&n);

        for(i=2; i<=55; i++){
            d = pow(n, (double)1.0/(double)i);
            d1 = ceil(d);
            d2 = floor(d);
            if(BigMod((ll)d1, i) == n || BigMod((ll)d2, i) == n){
                f = 1;
                goto HELL;
            }
        }

        HELL:;
        f ? puts("YES") : puts("NO");
    }


    return 0;
}












