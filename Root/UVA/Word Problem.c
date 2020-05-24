#include <stdio.h>
#include <string.h>

typedef struct
{
    char dic[10];
    int a;
} data;
int proof[7];

int main()
{
    data arr[1000];
    char word[7],str[1000];
    int i,j,k,l,n,m,len,c,s,d;
    i=0;
    while(gets(arr[i].dic))
    {
        arr[i].a=strlen(arr[i].dic);
        if(arr[i].a==1 && arr[i].dic[0]=='#')
            break;
        i++;
    }
    l=i;
    while(gets(str))
    {
        len=strlen(str);
        if(len==1 && str[0]=='#')
            break;
        c=0;
        for(i=0; i<len; i++)
        {
            if(str[i]!=' ')
                word[c++]=str[i];
        }
        d=c;
        s=0;
        for(i=0; i<l; i++)
        {
            m=0;
            for(j=0; j<arr[i].a; j++)
            {
                for(k=0; k<d; k++)
                {
                    if((arr[i].dic[j]==word[k]) && proof[k]==0)
                    {
                        proof[k]=1;
                        m++;
                        break;
                    }
                }
            }
            if(m==arr[i].a)
                s++;
            for(j=0;j<7;j++)
                proof[j]=0;
        }
        printf("%d\n",s);
    }

    return 0;
}
