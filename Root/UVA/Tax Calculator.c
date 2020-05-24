#include <stdio.h>
#include <math.h>

int main()
{
    long long income,i,j,k,l,n,m;
    double tax;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        tax=0;
        scanf("%lld",&income);
        income-=180000;
        if(income > 0 && income < 300000)
        {
            tax+=(income/10.0);
            income-=300000;
        }
        else if(income >= 300000)
        {
            tax+=300000/10.0;
            income-=300000;
        }
        if(income > 0 && income < 400000)
        {
            tax+=(income*15.0)/100.0;
            income-=400000;
        }
        else if(income >= 400000)
        {
            tax+=(400000*15.0)/100.0;
            income-=400000;
        }
        if(income > 0 && income < 300000)
        {
            tax+=(income/5.0);
            income-=300000;
        }
        else if(income >= 300000)
        {
            tax+=300000/5.0;
            income-=300000;
        }
        if(income > 0)
        {
            tax+=income/4.0;
        }
        tax=ceil(tax);
        if(tax>0 && tax <2000)
            tax=2000;
        printf("Case %lld: %.0lf\n",i,tax);
    }

    return 0;
}
