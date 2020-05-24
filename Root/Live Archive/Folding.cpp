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
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

#define X first
#define Y second



#define SZ  110

int dp[SZ][SZ];
char str[SZ];

bool check(int i, int start, int end) {
    if((end - start + 1) % (i - start + 1) != 0) return 0;
    int j, k;
    for(j = start, k = start; j <= end; j++, k++) {
        if(k > i) k = start;
        if(str[j] != str[k])
            return 0;
    }
    return 1;
}

int solve(int start, int end) {
    int &ret = dp[start][end];
    if(~ret) return ret;
    if(start == end) return ret = 1;

    ret = end-start+1;

    for(int i = start; i < end; i++) {
        ret = min(ret, solve(start, i) + solve(i+1, end));
    }

    for(int i = start; i < end; i++) {
        if(check(i, start, end)) {
            int p = (end - start + 1) / (i - start + 1);
            int k = 3 + (p > 9) + (p > 99);
            ret = min(ret, k + solve(start, i));
        }
    }

    return ret;
}

void path_print(int start, int end) {
    if(end == start) {
        printf("%c", str[start]);
        return;
    }

    for(int i = start; i < end; i++) {
        if(dp[start][end] == dp[start][i] + dp[i+1][end]) {
            path_print(start, i);
            path_print(i+1, end);
            return;
        }
    }

    for(int i = start; i < end; i++) {
        if(check(i, start, end)) {
            int p = (end - start + 1) / (i - start + 1);
            int k = 3 + (p > 9) + (p > 99);

            if(k + dp[start][i] == dp[start][end]) {
                printf("%d(", p);
                path_print(start, i);
                printf(")");
                return;
            }
        }
    }

    for(int i = start; i <= end; i++)
        printf("%c", str[i]);

    return;
}

int main() {
    while(scanf("%s", str) == 1) {
        mem(dp, -1);
        solve(0, strlen(str)-1);
        path_print(0, strlen(str)-1);
        printf("\n");
    }

    return 0;
}





