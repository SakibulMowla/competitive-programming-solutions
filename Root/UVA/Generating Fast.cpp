#include "bits/stdc++.h"

using namespace std;

int col[12];
char arr[12];
char tmp[12];
char str[12];
int unq;
int N;

set <char> ms;
set <char>::iterator it;
char mp[300];

void bctk(int indx) {
    if(indx == N) {
        int i;
        tmp[indx] = '\0';
        printf("%s\n",tmp);
        return;
    }

    int i;

    for(i=0; i<unq; i++) {
        if(col[i]) {
            tmp[indx] = str[i];
            col[i]--;

            bctk(indx+1);

            col[i]++;
        }
    }

    return;
}


int main() {
//    freopen("1.txt","r",stdin);
    int i, j, k, n;

    scanf("%d",&n);

    while(n--) {
        scanf("%s",arr);
        N = strlen(arr);
        memset(col, 0, sizeof col);
        ms.clear();

        for(i=0; arr[i]; i++) ms.insert(arr[i]);
        j = 0;
        unq = ms.size();

        for(it=ms.begin();it!=ms.end();it++){
            mp[*it] = j++;
            str[j-1] = *it;
        }

        for(i=0; arr[i]; i++) {
            col[mp[arr[i]]]++;
        }

        bctk(0);
        puts("");
    }


    return 0;
}


