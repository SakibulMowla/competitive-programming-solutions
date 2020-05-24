#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;


int main() {
    ll n, answer;
    int i, test, j;

    scanf("%d",&test);

    while(test--){
        scanf("%lld",&n);
        answer = (n*(n-1))/2;
        for(i=0;i<n;i++) scanf("%d",&j);
        printf("%lld\n",answer);
    }


    return 0;
}
















