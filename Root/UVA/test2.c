#include "stdio.h"

int main()
{
    int m, a, r, g, i, t, n, cnt, j;
    char arr[610];

    scanf("%d",&n);
    while(n--)
    {
        scanf(" %s",arr);
        m = a = r = g = i = t = cnt = 0;
        for(j=0;arr[j];j++)
        {
            if(arr[j] == 'M')
                m++;
            if(arr[j] == 'A')
                a++;
            if(arr[j] == 'R')
                r++;
            if(arr[j] == 'G')
                g++;
            if(arr[j] == 'I')
                i++;
            if(arr[j] == 'T')
                t++;
        }
        while(m>=1 && a>=3 && r>=2 && g>=1 && i>=1 && t>=1)
        {
            cnt++;
            m-=1;
            a-=3;
            r-=2;
            g-=1;
            i-=1;
            t-=1;
        }
        printf("%d\n",cnt);
    }

    return 0;
}

