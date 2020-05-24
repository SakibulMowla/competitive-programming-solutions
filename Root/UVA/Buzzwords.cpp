#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define SZ  1010

char str[SZ];
int revSA[SZ],SA[SZ];
int cnt[SZ] , nxt[SZ];
bool bh[SZ],b2h[SZ];
int lcp[SZ];


bool cmp(int i,int j){
    return str[i]<str[j];
}

void sortFirstChar(int n){
    int i;
    for(i=0; i<n; i++)
        SA[i] = i;
    sort(SA, SA+n,cmp);

    for(i=0; i<n; i++)
    {
        bh[i] = ( i==0  || str[SA[i]]!=str[SA[i-1]]);
        b2h[i] = false;
    }
    return;
}

int CountBucket(int n){
    int i, j, bucket = 0;

    for(i=0,j; i<n ;i=j){
        j = i+1;
        while(j<n && bh[j]==false) j++;
        nxt[i] = j;
        bucket++;
    }
    return bucket;
}

void SetRank(int n){
    int i, j;
    for(i=0; i<n; i=nxt[i]){
        cnt[i] = 0;
        for(j=i; j<nxt[i] ;j++){
            revSA[SA[j]] = i;
        }
    }
    return;
}

void findNewRank(int l,int r,int step){
    int j, head;
    for(j=l; j<r; j++){
        int pre = SA[j] - step;
        if(pre>=0){
            head = revSA[pre];
            revSA[pre] = head+cnt[head]++;
            b2h[revSA[pre]] = true;
        }
    }
    return;
}

void findNewBucket(int l,int r,int step){
    int j, k, pre;
    for(j=l; j<r; j++){
        pre = SA[j] - step;
        if(pre>=0 && b2h[revSA[pre]]){
            for(k=revSA[pre]+1; b2h[k] && !bh[k]; k++) b2h[k] = false;
        }
    }
    return;
}

void buildSA(int n){
    int h, i;
    sortFirstChar(n);
    for(h=1; h<n; h<<=1){
        if(CountBucket(n)==n) break;
        SetRank(n);
        b2h[revSA[n-h]] = true;
        cnt[revSA[n-h]]++;

        for(i=0; i<n; i=nxt[i]){
            findNewRank(i,nxt[i] , h);
            findNewBucket(i , nxt[i] , h);
        }
        for(i=0; i<n; i++){
            SA[revSA[i]] = i;
            bh[i] |= b2h[i];
        }
    }
    return;
}

void buildLCP(int n){
    int len = 0, i, k, j;

    for(i=0; i<n; i++)
        revSA[SA[i]] = i;
    for(i=0; i<n; i++){
        k = revSA[i];
        if(k == 0){
            lcp[k] = 0;
            continue;
        }
        j = SA[k-1];
        while(str[i+len]==str[j+len]) len++;
        lcp[k] = len;
        if(len) len--;
    }
    return;
}

int solve(int n, int m){
    int i, j, ans, cnt;

    ans = 0;
    cnt = 1;
    for(i=1; i<n; i++){
        if(lcp[i] < m){
            ans = max(ans, cnt);
            cnt = 1;
        }
        else
            cnt++;
    }

    return max(ans, cnt);
}

char tmp[SZ];

int main() {
    int i, n, k;
    char *s;

    while(gets(tmp))
    {
        if(tmp[0] == '\0') break;
        s = strtok(tmp, " ");
        str[0] = '\0';
        while(s != NULL){
            strcat(str, s);
            s = strtok(NULL, " ");
        }

        n = strlen(str);

        buildSA(n);
        buildLCP(n);

        for(i=1; i<=n; i++){
            k = solve(n, i);
            if(k == 1){
                puts("");
                break;
            }
            printf("%d\n",k);
        }
    }

    return 0;
}

