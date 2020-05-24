#include <stdio.h>
#include <string.h>

typedef struct{
    char country[80];
    int n;
}data;
int main()
{
    data arr[2010],temp;
    int p,i,j,k,l,len;
    char name[100],str[100],ch,z;
    p=0;
    scanf("%d ",&k);
    for(i=0;i<k;i++)
    {
        gets(str);
        len=strlen(str);
        for(j=0;j<len;j++)
        {
            if(str[j]!=' ')
                name[j]=str[j];
            else
            {
                name[j]='\0';
                break;
            }
        }
        l=0;
        for(j=0;j<p;j++)
        {
            if(strcmp(name,arr[j].country)==0)
            {
                arr[j].n++;
                l=1;
                break;
            }
        }
        if(l==0)
        {
            strcpy(arr[p].country,name);
            arr[p].n=1;
            p++;
        }
    }
    for(i=0;i<p-1;i++)
    {
        for(j=i+1;j<p;j++)
        {
            if(strcmp(arr[i].country,arr[j].country) > 0)
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(i=0;i<p;i++)
        printf("%s %d\n",arr[i].country,arr[i].n);
    return 0;
}
