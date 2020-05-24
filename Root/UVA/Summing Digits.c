#include<stdio.h>
#include<string.h>

int sd(int n);
int main()
{
    int i;

    while((scanf("%d",&i))==1)
    {
        if(i==0)
            break;
        printf("%d\n",sd(i));
    }
    return 0;
}

int sd(int n)
{
    int j,sum;
    if(n<10)
        return n;
    else
    {
        sum=0;
        for(j=n;j>0;j/=10)
        {
            sum+=j%10;
        }
        return sd(sum);
    }
}
