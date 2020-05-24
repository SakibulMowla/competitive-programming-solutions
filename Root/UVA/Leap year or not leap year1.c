#include<stdio.h>
#include<string.h>

int main(void)
{
    char arr[10000];
    int i,j,k,l,c,sum,len,z=0;
    while(gets(arr))
    {
        len=strlen(arr);
        c=0;
        if(z!=0)
            printf("\n");
        if((((arr[len-2]-'0')*10+arr[len-1]-'0')%4==0 && (arr[len-1]!='0' || arr[len-2]!='0')) ||(arr[len-1]=='0' && arr[len-2]=='0' &&((arr[len-4]-'0')*10+arr[len-3]-'0')%4==0))
        {
            printf("This is leap year.\n");
            c++;
        }
        k=0;
        for(i=0; i<len; i++)
        {
            k=(k*10+(arr[i]-'0'))%15;
        }
        l=0;
        if(k==0)
        {
            printf("This is huluculu festival year.\n");
            l++;
        }
        j=0;
        if(c==1)
        {
            for(i=0; i<len; i++)
            {
                j=(j*10+(arr[i]-'0'))%55;
            }
            if(j==0)printf("This is bulukulu festival year.\n");
        }
        if(l==0 && c==0)
            printf("This is an ordinary year.\n");
        z++;
    }
    return 0;
}
