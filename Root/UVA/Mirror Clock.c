#include<stdio.h>

int main()
{
    int i,n,a,b;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d:%d",&a,&b);
        if(b==0)
        {
            a=12-(a%12);
        }
        else if(b!=0)
        {
            b=60-b;
            a=12-((a+1)%12);
        }
        if(a<10 && b<10)
            printf("0%d:0%d\n",a,b);
        else if(a<10 && b>=10)
            printf("0%d:%d\n",a,b);
        else if(a>=10 && b<10)
            printf("%d:0%d\n",a,b);
        else
            printf("%d:%d\n",a,b);

    }

    return 0;
}
