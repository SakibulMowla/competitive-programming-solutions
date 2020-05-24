#include<stdio.h>
#include<string.h>

char ar1[15],ar2[15];
int main()
{
    int i,j,k,sum,car,add1,add2,len1,len2;
    while(scanf("%s %s",ar1,ar2))
    {
        len1=strlen(ar1);
        len2=strlen(ar2);
        if(len1==1 && len2==1 && ar1[0]=='0' && ar2[0]=='0')
            break;
        car=0;k=0;
        if(len1>=len2)
        {
            for(i=len1-1,j=len2-1;i>=0;i--,j--)
            {
                add1=ar1[i]-'0';
                if(ar2[j]>='0' && ar2[j]<='9')
                    add2=ar2[j]-'0';
                else
                    add2=0;
                sum=add1+add2+car;
                car=sum/10;
                if(car>0)k++;
            }
        }
        else if(len1<len2)
        {
            for(j=len2-1,i=len1-1;j>=0;i--,j--)
            {
                add1=ar2[j]-'0';
                if(ar1[i]>='0' && ar1[i]<='9')
                    add2=ar1[i]-'0';
                else
                    add2=0;
                sum=add1+add2+car;
                car=sum/10;
                if(car>0)k++;
            }
        }
        if(k==0)
            printf("No carry operation.\n");
        else if(k==1)
            printf("1 carry operation.\n");
        else
            printf("%d carry operations.\n",k);
    }
    return 0;
}
