#include<stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        if((n%400==0)||(n%4==0 && n%100!=0)||(n%15==0)||(n%55==0 && (n%400==0 || (n%4==0 && n%100!=0))))
        {
            if((n%4==0 && n%100!=0)||(n%400==0))
                printf("This is leap year.\n");
            if(n%15==0)
                printf("This is huluculu festival year.\n");
            if(n%55==0 && (n%400==0 || (n%4==0 && n%100!=0)))
                printf("This is bulukulu festival year.\n");
        }
        else
            printf("This is an ordinary year.\n");
        printf("\n");
    }
    return 0;
}
