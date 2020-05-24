#include<stdio.h>
#include<string.h>
char arr[100];
int main()
{
    int i=0;
    while(gets(arr))
    {
        if(arr[0]=='#')
            break;
        i++;
        if(strcmp(arr,"HELLO")==0)
            printf("Case %d: ENGLISH\n",i);
        else if(strcmp(arr,"HOLA")==0)
            printf("Case %d: SPANISH\n",i);
        else if(strcmp(arr,"HALLO")==0)
            printf("Case %d: GERMAN\n",i);
        else if(strcmp(arr,"BONJOUR")==0)
            printf("Case %d: FRENCH\n",i);
        else if(strcmp(arr,"CIAO")==0)
            printf("Case %d: ITALIAN\n",i);
        else if(strcmp(arr,"ZDRAVSTVUJTE")==0)
            printf("Case %d: RUSSIAN\n",i);
        else
            printf("Case %d: UNKNOWN\n",i);
    }

    return 0;
}
