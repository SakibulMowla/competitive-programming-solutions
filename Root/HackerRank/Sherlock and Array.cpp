#include "stdio.h"

#define SZ 100000+10

int arr[SZ];

int main(){
    int t, n, m, i, j, k;

    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);
        for(i=1; i<=n; i++){
            scanf("%d",&j);
            arr[i] = j + arr[i-1];
        }
        k= 0;
        for(i=1; i<=n; i++){
            if(arr[i-1] == arr[n]-arr[i]){
                k = 1;
                break;
            }
        }
        printf("%s\n",k?"YES":"NO");
    }
}
