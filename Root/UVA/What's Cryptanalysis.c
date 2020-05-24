#include <stdio.h>
#include <string.h>

int count[200];
int main()
{
    int n,m,i,j,k,l,len,num[50],c,temp;
    char arr[1000],z;
    scanf("%d%c",&n,&z);
    for(l=0;l<n;l++)
    {
        gets(arr);
        len=strlen(arr);
        for(i=0;i<len;i++)
        {
            count[toupper(arr[i])]++;
        }
    }
    c=0;
    for(i=65;i<=90;i++)
    {
        if(count[i]>0)
            num[c++]=count[i];
    }
    k=c;
    for(i=0;i<k-1;i++)
        for(j=i+1;j<k;j++)
            if(num[i]<num[j])
            {
                temp=num[i];
                num[i]=num[j];
                num[j]=temp;
            }
    for(i=0;i<k;i++)
    {
        for(j=65;j<=92;j++)
        {
            if(num[i]==count[j])
            {
                printf("%c %d\n",j,count[j]);
                count[j]=0;
            }
        }
    }

    return 0;
}
