#include <stdio.h>
#include <string.h>

typedef struct
{
    char fac[2800];
} data;
data arr[1010];
char arr1[2800],arr2[2800],mul1[2800],mul2[2800],str[2800],rev[2800],res[2800];

int main(void)
{
    int s,p,i,j,k,l,n,m,c,car,sum,add1,add2,add,len1,len2,len3,len4,mul,len;
    res[0]='1';
    res[1]='\0';
    strcpy(arr[0].fac,res);

    for(s=1; s<1010; s++)
    {
        strcpy(arr1,res);

        len1=strlen(arr1);
        len2=sprintf(arr2,"%d",s);

        for(i=len2-1,p=0; i>=0; i--,p++)
        {
            strcpy(mul2,res);
            c=0;
            car=0;
            for(j=len1-1; j>=0; j--)
            {
                mul=((arr2[i]-'0')*(arr1[j]-'0'))+car;
                str[c++]=(mul%10)+'0';
                car=mul/10;
            }
            if(car>0)
                str[c++]=car+'0';
            for(k=c-1,l=0; k>=0; k--,l++)
                mul1[l]=str[k];
            for(j=0; j<p; j++)
                mul1[l++]='0';
            mul1[l]='\0';

            len3=strlen(mul1);
            len4=strlen(mul2);

            car=0;
            c=0;

            for(j=len3-1,k=len4-1; j>=0 || k>=0; j--,k--)
            {
                if(mul1[j]>='0' && mul1[j]<='9')
                    add1=mul1[j]-'0';
                else add1=0;
                if(mul2[k]>='0' && mul2[k]<='9')
                    add2=mul2[k]-'0';
                else add2=0;
                add=add1+add2+car;
                rev[c++]=(add%10)+'0';
                car=add/10;
            }
            if(car>0)
                rev[c++]=car+'0';
            for(k=c-1,j=0; k>=0; k--,j++)
            {
                res[j]=rev[k];
            }
            res[j]='\0';

            strcpy(mul1,res);
        }

        strcpy(arr[s].fac,res);
    }
    while(scanf("%d",&n)==1)
    {
        if(n==0)
        {
            printf("1\n");
        }
        else
        {
            len=strlen(arr[n-1].fac);
            sum=0;
            for(i=0;i<len;i++)
                sum+=(arr[n-1].fac[i]-'0');
            printf("%d\n",sum);
        }
    }

    return 0;
}
