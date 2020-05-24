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

ll leading(ll n, ll k) {
    double d = ((double)k * log10((double)n)) - (ll) ((double)k * log10((double)n));
//    printf("d = %lf\n",d);
    d = pow(10, d);
//    printf("d = %lf\n",d);
    return (ll)(d*100);
}

ll trailing(ll B,ll P,ll M) {
    ll R = 1LL;

    while(P){
        if(P&1LL) {
            R = (R*B)%M;
        }
        P >>= 1LL;
        B=(B*B)%M;
    }

    return R;
}


int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif


    int test;
    ll n, k;

    scanf("%d",&test);

    while(test--) {
        scanf("%lld %lld",&n,&k);
        printf("%03lld...%03lld\n",leading(n, k), trailing(n, k, 1000));
    }


    return 0;
}
















