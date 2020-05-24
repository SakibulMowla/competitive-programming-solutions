#include <stdio.h>

int arr[50000+10];
int main()
{
    int n,m,i,j,k,h,l,q;
    scanf("%d",&n);

    for(i=1; i<=n; i++)
        scanf("%d",&arr[i]);

    scanf("%d",&m);
    for(j=0; j<m; j++)
    {
        scanf("%d",&q);

        h=-1;
        l=-1;
        arr[0]=-1;

        for(i=1; i<=n ; i++)
        {
            if(q>=arr[i-1] && q < arr[i])
            {
                h=arr[i];
                for(k=i-1; k>0; k--)
                {
                    if(arr[k] < q)
                    {
                        l=arr[k];
                        break;
                    }
                }
                break;
            }

            if(i==n)
            {
                for(k=i; k>0; k--)
                {
                    if(arr[k] < q)
                    {
                        l=arr[k];
                        break;
                    }
                }
            }
        }
        if(l==-1)printf("X");
        else printf("%d",l);
        if(h==-1)printf(" X");
        else printf(" %d",h);
        printf("\n");

    }

    return 0;
}
