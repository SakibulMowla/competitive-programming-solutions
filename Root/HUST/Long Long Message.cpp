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


#define SZ  2*100010

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

char input_text[SZ];
int SA[SZ], revSA[SZ];
int lcp[SZ];
int N;

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

        while((i+max_match<N) && (j+max_match<N) && input_text[i+max_match] == input_text[j+max_match] && input_text[i+max_match] != '#' && input_text[j+max_match] != '#')
            max_match++;

        lcp[SApos] = max_match;
    }

    lcp[0] = 0;
}

int half;

int solve(){
    int i, ans = 0;

    for(i=1; i<N; i++){
        if((SA[i]>half && SA[i-1]>half) || (SA[i]<half && SA[i-1]<half)) continue;
        ans = max(ans, lcp[i]);
    }

    return ans;
}

void printSA(){
    int i;
    printf("SA: ");
    for(i=0; i<N; i++) printf("%d ",SA[i]);puts("");
    printf("lcp: ");
    for(i=1; i<N; i++) printf("%d ",lcp[i]);puts("");
    return;
}

char arr[SZ];

int main() {
//    #if defined JESI
//        freopen("Suffix_Array_Input.txt", "r", stdin);
//        freopen("Suffix_Array_Output.txt", "w", stdout);
//    #endif


    while(scanf("%s",input_text) == 1){
        half = strlen(input_text);
        scanf("%s",arr);
        strcat(input_text, "#");
        strcat(input_text, arr);
        N = strlen(input_text);

        buildSA();
        buildLCP();

        printf("%d\n",solve());

//        printSA();
    }

    return 0;
}














