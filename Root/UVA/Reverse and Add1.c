#include<stdio.h>
#include<string.h>

int main(void)
{
    char arr[20],z,add[20],rev[20];
    int len,i,j,k,l,n,flag,c,R,car,sum;
    scanf("%d%c",&n,&z);

    for(i=0; i<n; i++)
    {
        gets(arr);
        c=0;
        R=0;
        while(R==0)
        {
            len=strlen(arr);
            flag=0;
            for(j=0,k=len-1; j<len; j++,k--)
            {
                if(arr[j]!=arr[k])
                    flag++;
            }

            if(flag!=0)
            {
                car=0;
                c++;
                sum=0;
                for(j=0,k=len-1; j<len; j++,k--)
                {
                    sum=(arr[j]-'0')+(arr[k]-'0')+car;
                    add[j]=(sum%10)+'0';
                    car=sum/10;
                }

                if(car>0)
                {
                    add[len]=car+'0';
                    for(j=0,k=len; j<=len; j++,k--)
                        rev[j]=add[k];
                    rev[j]='\0';
                }
                else
                {
                    for(j=0,k=len-1; j<len; j++,k--)
                        rev[j]=add[k];
                   rev[j]='\0';
                }
                strcpy(arr,rev);
            }
            else if(flag==0)
            {
                printf("%d %s\n",c,arr);
                R++;
            }
        }
    }

    return 0;
}
