#include <stdio.h>
#include <math.h>

int main()
{
    int test , n , zeroes;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        zeroes = 0;
        while(n >= 5)
        {
            zeroes += n / 5;
            n /= 5;
        }
        printf("%d\n",zeroes);
    }

    return 0;
}
