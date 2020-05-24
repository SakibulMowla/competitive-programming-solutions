#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace  std;

#define SZ1 31622+10

bool arr[SZ1];
int prime[SZ1];
int cnt;

void sieve() {
    int i, j, k;

    k = sqrt(SZ1);
    for(i=3;i<=k;i+=2)
        if(!arr[i])
            for(j=i*i;j<SZ1;j+=i+i)
                arr[j] = 1;

    cnt = 0;
    prime[cnt++] = 2;

    for(i=3;i<SZ1;i+=2)
        if(!arr[i])
            prime[cnt++] = i;
}

int kin_prime(int n) {
    int i, j, k, ans;

    ans = n;
    k = sqrt(n);

    for(i=0; i<cnt && prime[i]<=k; i++) {
        if(n%prime[i] == 0) {
            while(n%prime[i] == 0) {
                n /= prime[i];
            }
            ans = ans / prime[i] * (prime[i] - 1);
            k = sqrt(n);
        }
    }

    if(n != 1)
        ans = ans / n * (n-1);

    return ans;
}

int main() {
    sieve();
    int n;

    while(scanf("%d",&n) && n){
        printf("%d\n",kin_prime(n));
    }

    return 0;
}













