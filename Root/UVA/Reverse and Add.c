#include<stdio.h>
#include<string.h>

int main()
{
    char arr[100],x[100],y[100],sum[100],z;
    int i,j,k,l,n,c,flag,car,add,len,len1;
    scanf("%d%c",&i,&z);
    for(n=0; n<i; n++)
    {
        for(k=0; k<100; k++)
        {
            arr[i]='\0';
            y[i]='\0';
            x[i]='\0';
            sum[i]='\0';
        }
        gets(arr);
        c=0;
        while(1)
        {
            len=strlen(arr);
            flag=0;
            for(j=0,k=len-1; j<len; j++,k--)
            {
                if(arr[j]!=arr[k])
                    flag++;
            }
            if(flag==0)
            {
                printf("%d %s\n",c,arr);
                break;
            }
            c++;
            for(j=0,k=len-1; j<len; j++,k--)
                x[j]=arr[k];
            car=0;
            for(l=0,j=len-1; j>=0; j--,l++)
            {
                add=(arr[j]-'0')+(x[j]-'0')+car;
                sum[l]=(add%10)+'0';
                car=add/10;
                k=l+1;
                if(j==0 && car>0)
                {
                    sum[k]=car+'0';
                    sum[k+1]='\0';
                }
            }
            len1=strlen(sum);
            for(l=0,j=len1-1; l<len1; l++,j--)
                arr[l]=sum[j];
            arr[l+1]='\0';
        }
    }
    return 0;
}
