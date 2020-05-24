#include <stdio.h>
#include<string.h>
int main()
{
    int i,len,count;
    char ch[1000],prech;

    prech=' ';

    while(gets(ch))
    {
        len=strlen(ch);
        count=0;
        for(i=0; i<len; i++)
        {

            if(((ch[i]>='A' && ch[i]<= 'Z') ||(ch[i]>='a' && ch[i]<='z')) &&(prech < 'A' || prech >'z' ||(prech >'Z' && prech <'a')))
                count++;
            prech=ch[i];
        }

        printf("%d\n",count);
    }

    return 0;

}
