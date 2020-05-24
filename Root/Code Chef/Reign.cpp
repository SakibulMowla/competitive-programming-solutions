#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

const ll inf = 1e17;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define SZ 100010

ll arr[SZ], kadfr[SZ], kadbk[SZ];

int main(){
    ll t, n, k, i, sum, best;

    scanf("%lld",&t);

    while(t--){
        scanf("%lld %lld",&n,&k);

        for(i=1;i<=n;i++) scanf("%lld",&arr[i]);

        best = -inf;
        sum = 0;

        for(i=1;i<=n;i++) {
            sum += arr[i];
            if(sum > best)
                best = sum;
            kadfr[i] = best;
            if(sum < 0)
                sum = 0;
        }

        best = -inf;
        sum = 0;

        for(i=n;i>=1;i--) {
            sum += arr[i];
            if(sum > best)
                best = sum;
            kadbk[i] = best;
            if(sum < 0)
                sum = 0;
        }

        best = -inf;

        for(i=1;i<=n-k-1;i++){
            if(kadfr[i] + kadbk[i+k+1] > best)
                best = kadfr[i] + kadbk[i+k+1];
        }

        printf("%lld\n",best);
    }


    return 0;
}

















