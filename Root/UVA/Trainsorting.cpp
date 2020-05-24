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
#include <limits.h>

//#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;


#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)


#define SZ  4010

int tmp[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t, n, i, val, strt, endd, ulim, dlim;
    int lo, hi, mid, pos;

    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);

        if(!n) {
            printf("0\n");
            continue;
        }

        for(i = 1; i <= 4000; i++)
            tmp[i] = -1;

        dlim = 2000;
        ulim = 4000;

        for(i = 1; i <= n; i++) {
            scanf("%d", &val);

            lo = dlim;
            hi = ulim;

            while(lo <= hi) {
                mid = (lo + hi) >> 1;
                if(tmp[mid] == -1 || val < tmp[mid]) {
                    hi = mid - 1;
                    pos = mid;
                }
                else {
                    lo = mid + 1;
                }
            }

            if(tmp[pos] != -1) {
                if(pos == dlim && val < tmp[pos]) {
                    dlim--;
                    tmp[pos-1] = val;
                }
                else
                    tmp[pos] = val;
            }
            else
                tmp[pos] = val;
        }

        for(i = 1; ; i++) {
            if(tmp[i] != -1) {
                strt = i;
                break;
            }
        }
        for(i = 4000; ; i--) {
            if(tmp[i] != -1) {
                endd = i;
                break;
            }
        }

        printf("%d\n", endd-strt+1);
    }

    return 0;
}

/*
5
5 10 1 9 3
*/











