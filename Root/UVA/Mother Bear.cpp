#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    char arr[10000],str[10000];
    int c,i,j,len1,len2;
    while(gets(arr))
    {
        if(strcmp(arr,"DONE")==0)
            break;
        len1=strlen(arr);
        c=0;
        for(i=0;i<len1;i++)
        {
            if(toupper(arr[i])>='A' && toupper(arr[i])<='Z')
                str[c++]=arr[i];
        }
        str[c]='\0';
        len2=strlen(str);
        c=0;
        for(i=0,j=len2-1;i<(len2/2);i++,j--)
        {
            if(toupper(str[i]) != toupper(str[j]))
            {
                c++;
                break;
            }
        }
        if(c==0)
            printf("You won't be eaten!\n");
        else
            printf("Uh oh..\n");
    }

    return 0;
}
