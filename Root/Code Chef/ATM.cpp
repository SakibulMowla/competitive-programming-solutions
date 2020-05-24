#include <stdio.h>

int main()
{
    int amount;
    double balance;
    while(scanf("%d %lf",&amount,&balance) == 2)
    {
        if(amount + 0.50 <= balance && amount % 5 == 0) printf("%.2lf\n",balance - amount - 0.50);
        else printf("%.2lf\n",balance);
    }

    return 0;
}
