#include <bits/stdc++.h>

using namespace std;


int main(){
    #if defined JESI
//        freopen("1.txt","r",stdin);
    #endif // defined

    int test=0, t, r, w, l;

    scanf("%d",&t);

    while(t--){
        scanf("%d",&r);
        l = r * 5;
        w = r * 3;
        printf("Case %d:\n",++test);
        printf("%d %d\n", -(9*l/20), (w/2));
        printf("%d %d\n", 11*l/20, (w/2));
        printf("%d %d\n", 11*l/20, -w/2);
        printf("%d %d\n", -(9*l/20), -w/2);
    }

    return 0;
}
