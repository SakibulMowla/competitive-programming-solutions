#include <stdio.h>
#include <string.h>

typedef struct
{
    char fac[20];
} data;
data arr[15];
char arr1[20],arr2[20],mul1[20],mul2[20],str[20],rev[20],res[20];

int main()
{
    int s,p,i,j,k,l,n,m,c,car,sum,add1,add2,add,len1,len2,len3,len4,mul;
    res[0]='1';
    res[1]='\0';
    strcpy(arr[0].fac,res);

    for(s=1; s<15; s++)
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
        if(n<0 && abs(n)%2==0)
            printf("Underflow!\n");
        else if(n<0 && abs(n)%2==1)
            printf("Overflow!\n");
        else if(n<8 && n>=0)
            printf("Underflow!\n");
        else if(n>13)
            printf("Overflow!\n");
        else
            printf("%s\n",arr[n-1].fac);
    }

    return 0;
}
