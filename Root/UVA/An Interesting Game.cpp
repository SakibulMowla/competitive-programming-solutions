#include <bits/stdc++.h>

using namespace std;


int main(){
    #if defined JESI
//        freopen("1.txt","r",stdin);
    #endif // defined

    int test=0, t, i, j, k, n, x;

    scanf("%d",&t);

    while(t--){
        scanf("%d %d %d",&n,&k,&x);
        int sum=0;
        for(i=1; i<=n; i++){
            if(i>=x && i<=x+k-1) continue;
            sum += i;
        }
        printf("Case %d: %d\n",++test,sum);
    }


    return 0;
}

