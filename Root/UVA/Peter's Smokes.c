#include<stdio.h>

int main()
{
    int sum,a,b,i;
    while((scanf("%d %d",&a,&b))==2)
    {
        sum=a;
        for(i=a;i>=b;i=(i/b)+(i%b))
        {
            sum+=i/b;
        }
        printf("%d\n",sum);
    }

    return 0;
}
