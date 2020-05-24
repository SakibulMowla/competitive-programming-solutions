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

using namespace  std;

typedef long long ll;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)

#define SZ 20010

int dragon[SZ], knight[SZ];

int solve(int n, int m){
    int i, j, k, cnt = 0;

    sort(dragon+1, dragon+n+1);
    sort(knight+1, knight+m+1);

    j = 1;
    k = 0;

    for(i=1;i<=n;i++){
        while(j <= m){
            if(knight[j] >= dragon[i]){
                k += knight[j];
                j++;
                cnt++;
                break;
            }
            j++;
        }
    }

    if(cnt == n) return k;
    return -1;
}

int main() {
    int n, m, i, k;

    while(scanf("%d %d",&n,&m) == 2){
        if(n == 0 && m == 0) break;

        REP1(i, 1, n) scanf("%d",&dragon[i]);
        REP1(i, 1, m) scanf("%d",&knight[i]);

        k = solve(n, m);
        k == -1 ? printf("Loowater is doomed!\n") : printf("%d\n",k);
    }



    return 0;
}















