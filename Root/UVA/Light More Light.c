#include<stdio.h>

int main(void)
{
    unsigned long long int n,i,c;
    while((scanf("%llu",&n))==1)
    {
        c=0;
        if(n==0)
            break;
        if(n%2==1)
        {
            for(i=1; i<=n; i+=2)
                if(n%i==0)
                    c++;
        }
        else
        {
            for(i=1; i<=n; i++)
                if(n%i==0)
                    c++;
        }
        if(c%2==1)
            printf("yes\n");
        else if(c%2==0)
            printf("no\n");
    }

    return 0;
}
