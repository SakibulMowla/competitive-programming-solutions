#include <stdio.h>

int main()
{
    int n,m,k,l,b1,b2,b;
    scanf("%d",&l);
    for(k=0;k<l;k++)
    {
        scanf("%d %d",&n,&m);

        b1=b2=0;
        b1=(n-2)/3;
        if((n-2)%3>0)
            b1++;
        if(m>=3)
        b2=(m-2)/3;
        if((m-2)%3>0)
            b2++;

        b=b1*b2;
        printf("%d\n",b);
    }

    return 0;
}
