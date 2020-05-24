#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define SZ  2000000+10

int phi[SZ], dept[SZ];

void totient() {
    int i, j;
    for(i = 2; i <= 2000000; i++)
        if(!phi[i])
            for(j = i; j <= 2000000; j += i) {
                if(!phi[j])
                    phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
    return;
}

void depth_of_phi() {
    int i, j, k;
    for(i = 2; i <= 2000000; i++) {
        j = i;
        k = 0;
        while(j != 1) {
            k++;
            j = phi[j];
        }
        dept[i] = k;
    }
    return;
}

ll sum[SZ];

void cumulative() {
    int i;
    for(i = 2; i <= 2000000; i++) {
        sum[i] = (ll)dept[i] + sum[i-1];
    }
    return;
}

int main() {

    totient();
    depth_of_phi();
    cumulative();

    int t, n, m;

    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &n, &m);
        if(n > m) swap(n, m);
        printf("%lld\n", sum[m] - sum[n-1]);
    }

    return 0;
}


