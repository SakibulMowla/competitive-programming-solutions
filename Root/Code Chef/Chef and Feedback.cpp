#include "stdio.h"
#include "string.h"

int main() {
    int t, i, n;
    char arr[100010];
    bool f;

    scanf("%d",&t);

    while(t--){
        scanf("%s",arr);
        f = 0;
        n = strlen(arr);
        for(i=0;i<=n-3;i++){
            if((arr[i]=='0'&&arr[i+1]=='1'&&arr[i+2]=='0') || (arr[i]=='1'&&arr[i+1]=='0'&&arr[i+2]=='1')){
                f = 1;
                break;
            }
        }
        f ? puts("Good") : puts("Bad");
    }


    return 0;
}












