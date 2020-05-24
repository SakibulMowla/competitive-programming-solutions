#include "stdio.h"


int main()
{
    int a,b,n,cnt,dif;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&a,&b);
        cnt = 0;
        while(a && b)
        {
            if(a > b)
            {
                dif = a - b;
                cnt += dif / b + 1;
                a -= (dif / b + 1) * b;
            }
            else
            {
                dif = b - a;
                cnt += dif / a + 1;
                b -= (dif / a + 1) * a;
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}
