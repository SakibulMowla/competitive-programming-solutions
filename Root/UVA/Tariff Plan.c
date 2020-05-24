#include <stdio.h>

int main()
{
    int n,p,i,q,k,l,arr[100],m,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&p);
        m=j=0;
        for(q=0;q<p;q++)
        {
            scanf("%d",&arr[q]);
            k=arr[q]/30;
            l=arr[q]/60;
            m+=10*(k+1);
            j+=15*(l+1);
        }
        if(m<j)
            printf("Case %d: Mile %d\n",i+1,m);
        else if(j<m)
            printf("Case %d: Juice %d\n",i+1,j);
        else if(m==j)
            printf("Case %d: Mile Juice %d\n",i+1,m);
    }
    return 0;
}
