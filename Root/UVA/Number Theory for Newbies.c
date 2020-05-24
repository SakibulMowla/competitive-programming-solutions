#include <stdio.h>
#include <string.h>

int main()
{
    long long  n,i,j,len,max_num,min_num,res;
    char max[20],min[20],temp;
    while(scanf("%lld",&n)==1)
    {
        len=sprintf(min,"%lld",n);
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if(min[i]>min[j])
                {
                    temp=min[i];
                    min[i]=min[j];
                    min[j]=temp;
                }
            }
        }
        for(i=0,j=len-1;i<len;i++,j--)
        {
            max[i]=min[j];
        }
        max[i]='\0';
        if(min[0]=='0')
        {
            for(i=1;i<len;i++)
            {
                if(min[i]>'0')
                {
                    min[0]=min[i];
                    min[i]='0';
                    break;
                }
            }
        }
        min_num=0;
        max_num=0;
        for(i=0;i<len;i++)
        {
            min_num=min_num*10+(min[i]-'0');
            max_num=max_num*10+(max[i]-'0');
        }
        res=max_num-min_num;
        printf("%lld - %lld = %lld = 9 * %lld\n",max_num,min_num,res,res/9);
    }
    return 0;
}
