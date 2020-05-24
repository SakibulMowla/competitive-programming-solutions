#include<stdio.h>

int main()
{
    int n,i,j,c=0;
    while((scanf("%d",&n))==1)
    {
        if(n<0)
            break;
        c++;
        j=0;
        for(i=1;i<n;i*=2)
        {
            j++;
        }
        printf("Case %d: %d\n",c,j);
    }

    return 0;
}
