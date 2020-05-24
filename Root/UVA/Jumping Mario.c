#include<stdio.h>

int main()
{
    int m,n,i,j[1000],h,l,p,q;

    scanf("%d",&n);
    for(q=0;q<n;q++)
    {
        scanf("%d",&m);
        h=0;l=0;
        for(i=0;i<m;i++)
        {
            scanf("%d",&j[i]);
            if(i==0)
            {
                p=j[i];
                continue;
            }
            else
            {
                if(j[i]>p)
                    h++;
                else if(j[i]<p)
                    l++;

                p=j[i];
            }
        }
        printf("Case %d: %d %d\n",q+1,h,l);
    }

    return 0;
}
