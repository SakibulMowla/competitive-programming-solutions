#include "bits/stdc++.h"

#define SZ 100010
double arr[SZ];

int main() {
    int i, t, n, j;
    double d, inc, c;
    char ch[12];

    arr[1] = 0.45;
    inc = 0.495;
    c = 0.0045;

    for(i=2; i<SZ; i++) {
        arr[i] = arr[i-1] + inc;
        if(i < 20) {
            inc += c;
            c /= 10.00;
        }
    }

    scanf("%d",&t);

    while(t--) {
        n = 0;
        scanf("%s",ch);
        for(i=0; ch[i]; i++)
            n = (n*10) + ch[i]-'0';
        printf("%.12lf\n",arr[n]);
    }

    return 0;
}
