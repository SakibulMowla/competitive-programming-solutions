#include <stdio.h>
#include <string.h>

int len(char *a)
{
    int n=0;
    while(a[n++]){;}
    return n-1;
}

int cmp(char *a,char *b)
{
    int len1,len2,i;
    len1=len(a);
    len2=len(b);
    if(len1!=len2) return 1;
    for(i=0;i<len1 && i<len2;i++)
    {
        if(a[i]!=b[i]) break;
    }

    if(i==len1) return 0;
    else return 1;
}

int compare(char *a,char *b)
{
    int len1,len2,i;

    len1=len(a);
    len2=len(b);

    for(i=0;i<len1 && i<len2;i++)
    {
        if(a[i] != b[i])
            break;
    }
    if(i==len1 || i==len2) return 0;
    else return 1;
}

int main()
{
    char str[20][20];
    int i,j,t,k,res,flag;
    t=0;k=0;
    while(scanf("%s",str[t++])==1)
    {
        if(cmp(str[t-1],"9")==0)
        {
            ++k;
            flag=1;
            for(i=0;i<t-1;i++)
            {
                for(j=i+1;j<t-1;j++)
                {
                    flag=compare(str[i],str[j]);
                    if(flag==0)
                        break;
                }
                if(flag==0)
                    break;
            }
            if(flag==0)
                printf("Set %d is not immediately decodable\n",k);
            else
                printf("Set %d is immediately decodable\n",k);
            t=0;
        }
    }
    return 0;
}
