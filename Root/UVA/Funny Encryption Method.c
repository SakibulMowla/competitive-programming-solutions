#include<stdio.h>
#include<math.h>

int main()
{
    int i,j,k,l,n,m,c,d,sum;
    scanf("%d",&n);
    for(m=0;m<n;m++)
    {
        c=0;d=0;
        scanf("%d",&i);
        for(k=i;k>0;k/=2)
            if(k%2==1)c++;
        sum=0;
        for(k=i,l=0;k>0;l++,k/=10)
        {
            sum+=(k%10)*pow(16,l);
        }
        for(k=sum;k>0;k/=2)
            if(k%2==1)d++;
        printf("%d %d\n",c,d);
    }
    return 0;
}
