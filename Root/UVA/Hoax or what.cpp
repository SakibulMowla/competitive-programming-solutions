
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

//inline void inp( int &n ){
//    n=0;
//    int ch=getchar_unlocked();int sign=1;
//    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
//    while(  ch >= '0' && ch <= '9' )
//            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
//    n=n*sign;
//}


multiset <int> ms;

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, k, i, lo, hi;
    ll ans;

    while(scanf("%d",&n) == 1 && n){
        ans = 0LL;
        ms.clear();
        while(n--){
            scanf("%d",&k);
//            inp(k);
            while(k--){
                scanf("%d",&i);
//                inp(i);
                ms.insert(i);
            }
            lo = *(ms.begin());
            hi = *(--ms.end());
            ans += hi - lo;
            ms.erase(ms.begin());
            ms.erase(--ms.end());
        }
        printf("%lld\n",ans);
    }


    return 0;
}












