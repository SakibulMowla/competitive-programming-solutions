#include <stdio.h>
#include <string.h>

int count[130];
int main()
{
    int i,m,len;
    char arr[1000];
    while(gets(arr))
    {
        len=strlen(arr);
        for(i=0;i<len;i++)
        {
            if(toupper(arr[i])>='A' && toupper(arr[i])<='Z')
                count[arr[i]]++;
        }
        m=0;
        for(i=65;i<=90;i++)
        {
            if(count[i]>m)
                m=count[i];
        }
        for(i=97;i<=122;i++)
        {
            if(count[i]>m)
                m=count[i];
        }
        for(i=65;i<=90;i++)
        {
            if(count[i]==m)
                printf("%c",i);
        }
        for(i=97;i<=122;i++)
        {
            if(count[i]==m)
                printf("%c",i);
        }
        printf(" %d\n",m);
        memset(count,0,sizeof(count));
    }

    return 0;
}
