#include <stdio.h>

int main()
{
    int n,m,i,fac,n_p_m,five,two,k;

    while(scanf("%d %d",&n,&m) == 2)
    {
        fac = 1;
        n_p_m = n - m + 1;
        five = 0;
        two = 0;
        for(i=n;i>=n_p_m;i--)
        {
            k = i;
            while(k%2 == 0)
            {
                k /= 2;
                two++;
            }
            while(k%5 == 0)
            {
                k /= 5;
                five++;
            }
            fac = (fac*k) % 10;
        }
        for(i=two;i<five;i++)
        {
            fac = (fac*5) %10;
        }
        for(i=five;i<two;i++)
        {
            fac = (fac*2) % 10;
        }
        printf("%d\n",fac%10);
    }
    return 0;
}
