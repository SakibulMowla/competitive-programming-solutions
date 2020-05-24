#include <stdio.h>

int main()
{
    double d,sum;
    int cnt;
    while(scanf("%lf",&d) == 1 && d != 0.00)
    {
        sum = 0;
        cnt = 0;
        while(sum <= d)
        {
            cnt++;
            sum += 1.0 / (cnt+1);
        }
        printf("%d card(s)\n",cnt);
    }

    return 0;
}
