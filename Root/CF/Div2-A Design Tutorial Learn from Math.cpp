#include "bits/stdc++.h"
int main() {
    int n; scanf("%d", &n);
    printf("%d %d\n",(n&1)?9:4,(n&1)?(n-9):(n-4));
}
