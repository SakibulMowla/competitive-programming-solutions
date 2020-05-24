#include <stdio.h>
#include <string.h>

int arr1[1000010],arr2[1000010];
char inter1[1000010],inter2[1000010];

int main()
{
    long int m,n,i,j,k,l,c,add1,add2,sum,car,len;
    scanf("%ld",&n);
    for(m=0;m<n;m++)
    {
        scanf("%ld",&len);
        for(i=0;i<len;i++)
        {
            scanf("%ld",&arr1[i]);
            scanf("%ld",&arr2[i]);
        }
        car=sum=0;
        for(i=len-1,j=0;i>=0;i--,j++)
        {
            sum=arr1[i]+arr2[i]+car;
            car=sum/10;
            inter1[j]=(sum%10)+'0';
        }
        if(car>0)
        {
            inter1[j++]=car+'0';
            inter1[j]='\0';
        }
        else
            inter1[j]='\0';
        k=j;
        for(i=0,j=k-1;i<k;i++,j--)
            inter2[i]=inter1[j];
        inter2[i]='\0';
        printf("%s\n",inter2);
        if(m!=n-1)
        printf("\n");
    }

    return 0;
}
