#include<stdio.h>

int GCD(int a,int b);
int main()
{
    int g,i,j,n;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        g=0;
        for(i=1;i<n;i++)
            for(j=i+1;j<=n;j++)
                g+=GCD(i,j);
        printf("%d\n",g);
    }
    return 0;
}
int GCD(int a,int b)
{
    if(b==0)
        return a;
    return(GCD(b,a%b));
}
