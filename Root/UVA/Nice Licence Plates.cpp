#include "bits/stdc++.h"

int main()
{
    int n, a, p, b, i;
    char arr[10];

    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",arr);
        a = 0;
        p = 2;
        for(i=0;i<3;i++)
        {
            a += pow(26, p) * (arr[i]-'A');
            p--;
        }
        b = 0;
        for(i=4;i<8;i++)
        {
            b = (b*10) + arr[i]-'0';
        }
        a = a - b;
        if(a < 0) a = -a;
        if(a <= 100)
            printf("nice\n");
        else
            printf("not nice\n");
    }

    return 0;
}
