#include <stdio.h>
#include <math.h>

int main()
{
    unsigned long long  n,m,j,i,k,l,x,count;
//    freopen("Street Numbers.txt","w",stdout);
    count=0;
    for(i=1;count!=10;i++)
    {
        n=2*i*i;
        for(j=i+1;;j++)
        {
            x=j*j+j;
            if(x>n)break;
            if(x==n)
            {
                printf("%10llu%10llu\n",i,j);
                ++count;
                break;
            }
        }
    }
    return 0;
}
