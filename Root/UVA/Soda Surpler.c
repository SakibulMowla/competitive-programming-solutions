#include<stdio.h>

int main(void)
{
    int n,m,i,j,k,l,p,s;
    scanf("%d",&n);
    for(m=0;m<n;m++)
    {
        scanf("%d %d %d",&i,&j,&k);
        s=i+j;
        p=0;
        for(l=s;l>=k;l=(l/k)+(l%k))
        {
            p+=(l/k);
        }
        printf("%d\n",p);
    }

    return 0;
}
