#include <stdio.h>
#include <string.h>

char in[110][130],out[110][130];
char num1[10000],num2[10000];
int main()
{
    int n,m,i,k,j,count,len,flag;
    char z;
    count=0;
    while(scanf("%d%c",&n,&z) == 2  && n)
    {
        flag=0;
        for(i=0; i<n; i++)
        {
            gets(in[i]);
        }
        scanf("%d%c",&m,&z);
        for(i=0; i<m; i++)
        {
            gets(out[i]);
        }
        if(n==m)
        {
            k=0;
            for(i=0; i<n; i++)
            {
                if(strcmp(in[i],out[i]) == 0)
                    k++;
            }
            if(k==n)
            {
                printf("Run #%d: Accepted\n",++count);
                flag=1;
            }
        }
        if(n!=m || flag==0)
        {
            k=0;
            for(i=0; i<n; i++)
            {
                len=strlen(in[i]);
                for(j=0; j<len; j++)
                {
                    if(in[i][j] >='0' && in[i][j] <='9')
                        num1[k++]=in[i][j];
                }
            }
            num1[k]='\0';
            k=0;
            for(i=0; i<m; i++)
            {
                len=strlen(out[i]);
                for(j=0; j<len; j++)
                {
                    if(out[i][j] >='0' && out[i][j] <='9')
                        num2[k++]=out[i][j];
                }
            }
            num2[k]='\0';
            if(strcmp(num1,num2) == 0)
                printf("Run #%d: Presentation Error\n",++count);
            else
                printf("Run #%d: Wrong Answer\n",++count);
        }
    }
    return 0;
}
