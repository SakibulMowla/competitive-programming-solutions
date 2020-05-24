#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <assert.h>

using namespace  std;

typedef long long ll;

#define SZ 1010

ll MultMod(ll a,ll b,ll mod){
    a %= mod;
    b %= mod;
    ll ret=0;
    while(b){
        if(b&1){
            ret += a;
            if(ret >= mod) ret -= mod;
        }
        a = a<<1;
        if(a >= mod) a -= mod;
        b = b>>1;
    }
    return ret;
}

ll arr[SZ];

int main() {
    int t, n, i, beg, end, tmp;
    ll a, b, c, jog, gun;
    bool soja;
    char s[SZ];

    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);

        for(i=1;i<=n;i++) scanf("%lld",&arr[i]);

        scanf("%lld %lld %lld",&a,&b,&c);

        a %= c;
        b %= c;

        scanf("%s",s+1);

        soja = 1;
        beg = 1;
        end = n;
        jog = 0LL;
        gun = 1LL;

        for(i=1;i<=n;i++){
            if(s[i] == 'R'){
                soja = !soja;
            }

            else if(s[i] == 'A'){
                jog = (jog + a) % c;
            }

            else{
                jog = MultMod(jog, b, c);
                gun = MultMod(gun, b, c);
            }

            if(soja){
                tmp = beg;
                beg++;
            }
            else{
                tmp = end;
                end--;
            }

            arr[tmp] = MultMod(arr[tmp], gun, c);
            arr[tmp] = (arr[tmp] + jog) % c;

            if(i != 1) printf(" ");
            printf("%lld",arr[tmp]);
        }
        puts("");
    }

    return 0;
}













