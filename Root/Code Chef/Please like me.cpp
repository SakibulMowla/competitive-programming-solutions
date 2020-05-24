#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

int main() {
    int t;
    ll d, l, s, c;
    int i;

    scanf("%d",&t);

    while(t--){
        scanf("%lld %lld %lld %lld",&l,&d,&s,&c);
        for(i=2;i<=d;i++){
            s = s + c * s;
            if(s >= l) break;
        }
        s >= l ? puts("ALIVE AND KICKING") : puts("DEAD AND ROTTING");
    }

    return 0;
}













