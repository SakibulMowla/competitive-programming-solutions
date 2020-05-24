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


#define SZ  2*50000+10

struct data{
    int a, b, pos;
    data() {}
    data(int x, int y, int z){
        a = x, b = y, pos = z;
    }
};

data SAdt[SZ];

bool comp(data p, data q){
    if(p.a == q.a) return p.b < q.b;
    return p.a < q.a;
}

int input_text[SZ];
int SA[SZ], revSA[SZ];
int lcp[SZ];
int N;
int n, m;

void buildSA(){
    int i, cnt, pre;

    for(i=0; i<N; i++) revSA[i] = input_text[i];

    for(cnt=1; cnt<N; cnt<<=1){
        for(i=0; i<N; i++){
            SAdt[i].pos = i;
            SAdt[i].a = revSA[i];
            SAdt[i].b = (i + cnt < N) ? revSA[i+cnt] : -1;
        }

        sort(SAdt, SAdt+N, comp);

        for(i=0; i<N; i++){
            revSA[ SAdt[i].pos ] = (i-1>=0 && SAdt[i].a == SAdt[i-1].a && SAdt[i].b == SAdt[i-1].b) ? pre : i;
            pre = revSA[ SAdt[i].pos ];
        }
    }

    for(i=0; i<N; i++) SA[revSA[i]] = i;
}

void buildLCP(){
    int max_match=0, SApos, i, j;
    for(i=0; i<N; i++){
        SApos = revSA[i];
        if(SApos == 0) continue;
        if(max_match > 0) max_match--;

        j = SA[SApos-1];

        while((i+max_match<N) && (j+max_match<N) && input_text[i+max_match] == input_text[j+max_match])
            max_match++;

        lcp[SApos] = max_match;
    }

    lcp[0] = 0;
}

int solve(int k){
    int i, j, left, riht, cnt, res=0;
    bool f;

    for(i=1; i<N; i++){
        left = i;
        while(left < N && lcp[left] < k) left++;
        if(left == N) break;

        riht = left;
        while(riht < N && lcp[riht] >= k) riht++;

        f = 0;
        cnt = 0;

        for(j=left-1; j<riht; j++){
            if(SA[j] < n) cnt++;
            else if(SA[j] > n) f = 1;
        }

        if(f) res += cnt;
        i = riht;
    }

    return res;
}

void printSA(){
    int i;
    printf("SA: ");
    for(i=0; i<N; i++) printf("%d ",SA[i]);puts("");
    printf("lcp: ");
    for(i=1; i<N; i++) printf("%d ",lcp[i]);puts("");
    return;
}

int main() {
//    #if defined JESI
//        freopen("Suffix_Array_Input.txt", "r", stdin);
//        freopen("Suffix_Array_Output.txt", "w", stdout);
//    #endif

    int i, j, k;

    while(scanf("%d %d %d",&n,&m,&k) == 3){
        for(i=0; i<n; i++) scanf("%d",&input_text[i]);
        input_text[i++] = 10001;
        for(j=0; j<m; i++,j++) scanf("%d",&input_text[i]);

        N = n+m+1;

        buildSA();
        buildLCP();

        printf("%d\n",solve(k)-solve(k+1));

//        printSA();
    }

    return 0;
}














