#include <stdio.h>
#include <string.h>

typedef struct
{
    char fac[1000];
} data;
data arr[400];
char arr1[1000],arr2[1000],mul1[1000],mul2[1000],str[1000],rev[1000],res[1000];

int main()
{
    int s,p,i,j,k,l,n,m,c,car,sum,add1,add2,add,len1,len2,len3,len4,mul;
    res[0]='1';
    res[1]='\0';
    strcpy(arr[0].fac,res);

    for(s=1; s<400; s++)
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

    int n0,n1,n2,n3,n4,n5,n6,n7,n8,n9,len;
    while(scanf("%d",&n)==1)
    {
        if(n==0) break;

        n0=n1=n2=n3=n4=n5=n6=n7=n8=n9=0;
        len=strlen(arr[n-1].fac);

        for(i=0;i<len;i++)
        {
            if(arr[n-1].fac[i]=='0') n0++;
            else if(arr[n-1].fac[i]=='1') n1++;
            else if(arr[n-1].fac[i]=='2') n2++;
            else if(arr[n-1].fac[i]=='3') n3++;
            else if(arr[n-1].fac[i]=='4') n4++;
            else if(arr[n-1].fac[i]=='5') n5++;
            else if(arr[n-1].fac[i]=='6') n6++;
            else if(arr[n-1].fac[i]=='7') n7++;
            else if(arr[n-1].fac[i]=='8') n8++;
            else if(arr[n-1].fac[i]=='9') n9++;
        }
        printf("%d! --\n",n);
        printf("   (0)%4d    (1)%4d    (2)%4d    (3)%4d    (4)%4d\n",n0,n1,n2,n3,n4);
        printf("   (5)%4d    (6)%4d    (7)%4d    (8)%4d    (9)%4d\n",n5,n6,n7,n8,n9);
    }

    return 0;
}
