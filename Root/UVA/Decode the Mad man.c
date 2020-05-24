#include<stdio.h>
#include<string.h>

int main()
{
    int i,len;
    char arr[1000];
    while(gets(arr)){
    len=strlen(arr);
    for(i=0;i<len;i++)
    {
        if(arr[i]==' ')
            printf(" ");
        else if(tolower(arr[i])=='e')
            printf("q");
        else if(tolower(arr[i])=='r')
            printf("w");
        else if(tolower(arr[i])=='t')
            printf("e");
        else if(tolower(arr[i])=='y')
            printf("r");
        else if(tolower(arr[i])=='u')
            printf("t");
        else if(tolower(arr[i])=='i')
            printf("y");
        else if(tolower(arr[i])=='o')
            printf("u");
        else if(tolower(arr[i])=='p')
            printf("i");
        else if(tolower(arr[i])=='[')
            printf("o");
        else if(tolower(arr[i])==']')
            printf("p");
        else if(tolower(arr[i])=='d')
            printf("a");
        else if(tolower(arr[i])=='f')
            printf("s");
        else if(tolower(arr[i])=='g')
            printf("d");
        else if(tolower(arr[i])=='h')
            printf("f");
        else if(tolower(arr[i])=='j')
            printf("g");
        else if(tolower(arr[i])=='k')
            printf("h");
        else if(tolower(arr[i])=='l')
            printf("j");
        else if(tolower(arr[i])==';')
            printf("k");
        else if(tolower(arr[i])==39)
            printf("l");
        else if(tolower(arr[i])=='c')
            printf("z");
        else if(tolower(arr[i])=='v')
            printf("x");
        else if(tolower(arr[i])=='b')
            printf("c");
        else if(tolower(arr[i])=='n')
            printf("v");
        else if(tolower(arr[i])=='m')
            printf("b");
        else if(tolower(arr[i])==',')
            printf("n");
        else if(tolower(arr[i])=='.')
            printf("m");
    }printf("\n");
    }
    return 0;
}
