#include <stdio.h>

int main()
{
    long int n,i,j,b1,b2,b3,g1,g2,g3,c1,c2,c3,c[6],sum;

    while(scanf("%ld %ld %ld %ld %ld %ld %ld %ld %ld",&b1,&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3)==9)
    {
        c[0]=b2+b3+c1+c3+g1+g2;
        c[1]=b2+b3+g1+g3+c1+c2;
        c[2]=c2+c3+b1+b3+g1+g2;
        c[3]=c2+c3+g1+g3+b1+b2;
        c[4]=g2+g3+b1+b3+c1+c2;
        c[5]=g2+g3+c1+c3+b1+b2;
        sum=c[0];
        j=0;
        for(i=0; i<6; i++)
        {
            if(c[i]<sum)
            {
                sum=c[i];
                j=i;
            }
        }
        if(j==0)
            printf("BCG ");
        else if(j==1)
            printf("BGC ");
        else if(j==2)
            printf("CBG ");
        else if(j==3)
            printf("CGB ");
        else if(j==4)
            printf("GBC ");
        else if(j==5)
            printf("GCB ");
        printf("%ld\n",sum);
    }
    return 0;
}
