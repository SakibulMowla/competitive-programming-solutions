#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,m,i,k;
    while((scanf("%d",&n))==1)
    {
        if(n==0)
            break;
        if(n==1)
            printf("%d = %d\n",n,n);
        else if(n<0)
        {
            m=abs(n);
            printf("%d = -1",n);
            i=2;
            while(m!=1)
            {
                if(m%i==0)
                {
                    printf(" x %d",i);
                    m/=i;
                }
                else
                    i++;
            }
            printf("\n");
        }
        else if(n>0)
        {
            i=2;
            m=n;
            k=0;
            while(k==0)
            {
                if(m%2==1)
                {
                    printf("%d =",m);
                    break;
                }
                else if(m%i==0)
                {
                    printf("%d = %d",m,i);
                    m/=i;
                }
                k++;
            }
            while(m!=1)
            {
                while(n==m)
                {
                    if(n%i==0)
                    {
                        printf(" %d",i);
                        m/=i;
                    }
                    else
                        i++;
                }
                if(m%i==0)
                {
                    printf(" x %d",i);
                    m/=i;
                }
                else
                    i++;
            }
            printf("\n");
        }
    }

    return 0;
}
