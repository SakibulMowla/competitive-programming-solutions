#include <stdio.h>
#include <string.h>

typedef struct {
        char str1[100],str2[100];
} data;

int main()
{
    data arr[100];
    char nam[100];
    int i,j,n,m,len,c;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%s %s",arr[i].str1,arr[i].str2);
    for(i=0;i<m;i++)
    {
        scanf("%s",nam);
        c=0;
        for(j=0;j<n;j++)
        {
            if(strcmp(arr[j].str1,nam)==0)
            {
                printf("%s\n",arr[j].str2);
                c++;break;
            }
        }
        if(c!=0)continue;
        len=strlen(nam);
        if(nam[len-1]=='y' && nam[len-2]!='a'&& nam[len-2]!='e'&& nam[len-2]!='i'&& nam[len-2]!='o'&& nam[len-2]!='u')
        {
            nam[len-1]='i';
            nam[len]='e';
            nam[len+1]='s';
            nam[len+2]='\0';
        }
        else if(nam[len-1]=='o' || nam[len-1]=='s' || nam[len-1]=='x' || (nam[len-1]=='h' && nam[len-2]=='c') ||(nam[len-1]=='h' && nam[len-2]=='s'))
        {
            nam[len]='e';
            nam[len+1]='s';
            nam[len+2]='\0';
        }
        else
        {
            nam[len]='s';
            nam[len+1]='\0';
        }
        printf("%s\n",nam);
    }
    return 0;
}
