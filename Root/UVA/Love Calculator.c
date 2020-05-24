#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,sum1,sum2,t,len1,len2;
    char arr1[1000],arr2[1000];
    double d;
    while(gets(arr1) && gets(arr2))
    {
        sum1=0;
        sum2=0;
        len1=strlen(arr1);
        len2=strlen(arr2);
        for(i=0; i<len1; i++)
            if(toupper(arr1[i])>='A' && toupper(arr1[i])<='Z')
                sum1+=toupper(arr1[i])-64;
        while(sum1>9)
        {
            j=0;
            for(t=sum1; t>0; t/=10)
                j+=t%10;
            sum1=j;
        }
        for(i=0; i<len2; i++)
        {
            if(toupper(arr2[i])>='A' && toupper(arr2[i])<='Z')
                sum2+=toupper(arr2[i])-64;
        }
        while(sum2>9)
        {
            j=0;
            for(t=sum2; t>0; t/=10)
                j+=t%10;
            sum2=j;
        }

        if(sum1>=sum2)
            d=((double)sum2/(double)sum1)*100;
        else if(sum1<sum2)
            d=((double)sum1/(double)sum2)*100;
        printf("%.2lf %%\n",d);
    }

    return 0;
}
