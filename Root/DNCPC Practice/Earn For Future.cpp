#include <bits/stdc++.h>

using namespace std;


int main(){
    #if defined JESI
//        freopen("1.txt","r",stdin);
    #endif // defined

    int t, test=0, n, i, best;

    scanf("%d",&t);

    while(t--){
        best = 0;

        scanf("%d",&n);
        while(n--){
            scanf("%d",&i);
            best = max(best, i);
        }

        printf("Case %d: %d\n",++test,best);
    }

    return 0;
}


