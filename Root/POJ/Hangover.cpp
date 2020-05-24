#include "stdio.h"

#define SLF(n) scanf("%lf",&n)

int main()
{
    double d,n;
    int cnt,a;
    while(SLF(d)==1)
    {
        if(d == 0) break;
        n = 0;
        a = 2;
        cnt = 0;
        while(n < d)
        {
            n += 1 / (double)a++;
            cnt++;
        }
        printf("%d card(s)\n",cnt);
    }
    return 0;
}
