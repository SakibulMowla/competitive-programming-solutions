 #include<stdio.h>

int main(void)
{
    int i,j,k,l,n,m,p;
    scanf("%d",&n);
    for(m=0; m<n; m++)
    {
        scanf("%d %d",&i,&j);

        for(l=0; l<j; l++)
        {
            for(k=1; k<=i; k++)
            {
                for(p=1; p<=k; p++)
                    printf("%d",k);
                printf("\n");
            }

            for(k=i-1; k>0; k--)
            {
                for(p=1; p<=k; p++)
                    printf("%d",k);
                printf("\n");
            }

            if(m!=n-1 || l!=j-1)
                printf("\n");
        }

    }
    return 0;
}
