#include <stdio.h>
#include <string.h>

int count[200];
int main()
{
    int n,m,len,i,j,k,l,temp,str[200];
    char arr[1010];
    l=0;
    while(gets(arr))
    {
        len=strlen(arr);
        if(l>0)
            printf("\n");
        for(i=0;i<len;i++)
        {
            count[arr[i]]++;
        }
        k=0;
        for(i=32;i<=128;i++)
        {
            if(count[i]>0)
                str[k++]=count[i];
        }
        for(i=0;i<k-1;i++)
        {
            for(j=i+1;j<k;j++)
            {
                if(str[i]>str[j])
                {
                    temp=str[i];
                    str[i]=str[j];
                    str[j]=temp;
                }
            }
        }

        for(i=0;i<k;i++)
        {
            for(j=128;j>=32;j--)
            {
                if(str[i]==count[j])
                {
                    printf("%d %d\n",j,count[j]);
                    count[j]=0;
                }
            }
        }
        memset(count,0,sizeof count);
        memset(str,0,sizeof str);
        l++;
    }

    return 0;
}
