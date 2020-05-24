#include<stdio.h>

int GCD(int a,int b);
int main()
{
    int n,i,j,m,g,l;
    scanf("%d",&n);
    for(m=0;m<n;m++)
    {
        scanf("%d %d",&i,&j);
        g=GCD(i,j);
        l=(i*j)/g;
        if(g<=l)
            printf("%d %d\n",g,l);
        else
            printf("-1\n");
    }
    return 0;
}
int GCD(int a,int b)
{
    if(b==0)
        return a;
    return(GCD(b,a%b));
}
