#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "string"
#include "vector"
#include "set"
#include "queue"
#include "map"
#include "deque"
#include "iostream"
#include "assert.h"
#include "bitset"
#include "algorithm"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define pb push_back
#define mem(a, b) memset(a, b, sizeof(a))
#define sz(a) (int)a.size()
#define clr(a) a.clear()
#define MP(a, b) make_pair(a, b)

#define SZ 100000+10

char str[SZ];
int revSA[SZ], SA[SZ];
int cnt[SZ], nxt[SZ];
bool bh[SZ], b2h[SZ];
int lcp[SZ];

int seg[SZ*4];

void build(int cur,int st,int ed)
{
    if(st==ed)
    {
        seg[cur] = lcp[st];
        return;
    }

    int mid = (st+ed)>>1;

    build(cur*2 , st , mid);
    build(cur*2+1 , mid+1, ed);

    seg[cur] = min(seg[cur*2] , seg[cur*2+1]);
    return;
}


int get_sol(int cur,int st,int ed,int l,int r)
{
    if(st>r || ed<l ) return (1<<25);

    if(st>=l && ed<=r ) return seg[cur];

    int mid=  (st+ed)>>1;
    return min(get_sol(cur*2 , st , mid , l,r ) , get_sol(cur*2+1 ,mid+1 , ed, l,r));
}

int find_sol(int n,int i,int j)
{
    return get_sol(1,0 , n-1  , min(revSA[i],revSA[j])+1  , max(revSA[i],revSA[j]));
}


bool cmp(int i, int j){
    return str[i] < str[j];
}

void sortFirstChar(int n){
    int i;
    for(i=0; i<n; i++)
        SA[i] = i;
    sort(SA, SA+n, cmp);

    for(i=0; i<n; i++){
        bh[i] = (i == 0 || str[SA[i]] != str[SA[i-1]]);
        b2h[i] = false;
    }
    return;
}

int CountBucket(int n){
    int i, j, bucket=0;

    for(i=0; i<n; i=j){
        j = i+1;
        while(j<n && bh[j]==false) j++;
        nxt[i]  = j;
        bucket++;
    }
    return bucket;
}

void SetRank(int n){
    int i, j;
    for(i=0; i<n; i=nxt[i]){
        cnt[i] = 0;
        for(j=i; j<nxt[i]; j++){
            revSA[SA[j]] = i;
        }
    }
    return;
}

void findNewRank(int l, int r, int step){
    int j, head;
    for(j=l; j<r; j++){
        int pre = SA[j] - step;
        if(pre >= 0){
            head = revSA[pre];
            revSA[pre] = head+cnt[head]++;
            b2h[revSA[pre]] = true;
        }
    }
    return;
}

void findNewBucket(int l, int r, int step){
    int j, k, pre;
    for(j=l; j<r; j++){
        pre = SA[j] - step;
        if(pre >= 0 && b2h[revSA[pre]]){
            for(k=revSA[pre]+1; b2h[k] && !bh[k]; k++)
                b2h[k] = false;
        }
    }
    return;
}

void buildSA(int n){
    int h, i;
    sortFirstChar(n);
    for(h=1; h<n; h<<=1){
        if(CountBucket(n) == n) break;
        SetRank(n);
        b2h[revSA[n-h]] = true;
        cnt[revSA[n-h]]++;

        for(i=0; i<n; i=nxt[i]){
            findNewRank(i, nxt[i], h);
            findNewBucket(i, nxt[i], h);
        }
        for(i=0; i<n; i++){
            SA[revSA[i]] = i;
            bh[i] |= b2h[i];
        }
    }
    return;
}

void buildLCP(int n){
    int len=0, i, k, j;

    for(i=0; i<n; i++)
        revSA[SA[i]] = i;
    for(i=0; i<n; i++){
        k = revSA[i];
        if(k == 0){
            lcp[k] = 0;
            continue;
        }
        j = SA[k-1];
        while(str[i+len] == str[j+len]) len++;
        lcp[k] = len;
        if(len) len--;
    }
    return;
}

void printSA(int n){
    int i;
    printf("SA: ");
    for(i=0; i<n; i++) {
        for(int j = SA[i];j < n; j++) printf("%c", str[j]);
        printf("\n");
    }
    printf("LCP: ");
    for(i=1; i<n; i++) printf("%d ",lcp[i]); puts("");
    return;
}

int main()
{
    #ifdef PGD_LAB
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif
    int t;
    scanf("%d", &t);
    for (int cs = 1; cs <= t; cs++) {
        scanf("%s",str);
        int n = strlen(str);

        buildSA(n);
        buildLCP(n);

//        printSA(n);

        build(1, 0, n-1);
        int ans = 0, last = n;
        for(int i = 0, j = n - 1; j >= i; j--) {
            if(i == j) {
                ans++;
                break;
            }
            int tmp = find_sol(n, i, j);
//            printf(">>> %d %d %d\n", i, j, tmp);
            tmp = min(tmp, j - i);
            if(tmp >= last - j) {
//                printf(">>>>>>>>> %d %d\n", i, j);
                ans += 2;
                i += last - j;
                last = j;
            } else {

            }
        }

        printf("Case #%d: %d\n", cs, ans);
    }



    return 0;
}





