#include <bits/stdc++.h>

using namespace std;

#define SZ (500*500)+10

int arr[SZ], pos[SZ];

int main(){
    #if defined JESI
//        freopen("1.txt","r",stdin);
    #endif // defined

    int i, j, k, n, m, zeropos, cnt, tmp;
    int test=0, t;

    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);

        for(i=0; i<n*n; i++){
            scanf("%d",&arr[i]);
            pos[arr[i]] = i;
        }

        cnt = 0;
        while(pos[0] != 0){
            tmp = pos[0];
            pos[0] = pos[ pos[0] ];
            pos[tmp] = tmp;
            cnt++;
        }

        for(i=0; i<n*n; i++){
            if(pos[i] == i) continue;
            j = pos[i];
            k = pos[0];
            pos[0] = j;
            pos[i] = k;
            cnt++;

            while(pos[0] != 0){
                tmp = pos[0];
                pos[0] = pos[ pos[0] ];
                pos[tmp] = tmp;
                cnt++;
            }
        }

        printf("Case %d: %d\n",++test,cnt);
    }


    return 0;
}

