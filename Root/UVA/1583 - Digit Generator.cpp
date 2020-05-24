#include "bits/stdc++.h"

int calc(int n)
{
    int sum = n;
    while(n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int ans[100010];

int main()
{
    for(int i = 1; i <= 100000; i++)
    {
        int j = calc(i);
        if(j <= 100000 && !ans[j])
            ans[j] = i;
    }

    int t;
    scanf("%d", &t);

    while(t--)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
}
