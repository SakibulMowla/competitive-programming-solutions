#include <stdio.h>

int main()
{
    unsigned long long int a,b,i,j,k,l,n,m,v,c,pc;

    while(scanf("%llu %llu",&a,&b)==2)
    {
        if(a==0 && b==0) break;
        if(a>=b)
        {
            n=b;m=a;
        }
        else
        {
            n=a;m=b;
        }
        pc=0;
        for(j=n;j<=m;j++)
        {
            c=0;
            i=j;
            while(1)
            {
                if(i%2==0)
                {
                    i/=2;c++;
                }
                else if(i%2==1)
                {
                    i=(3*i)+1;c++;
                }
                if(i==1)
                    break;
            }
            if(c>pc)
            {
                pc=c;
                v=j;
            }
        }
        printf("Between %llu and %llu, %llu generates the longest sequence of %llu values.\n",n,m,v,pc);
    }
    return 0;
}
