#include<stdio.h>
#include<string.h>

int main()
{
    char arr[100],z;
    int i,n,j,len;
    scanf("%d%c",&n,&z);
    for(i=0;i<n;i++)
    {
        gets(arr);
        len=strlen(arr);
        if(len==3)
        {
            if((arr[0]=='o'&&arr[1]=='n') || (arr[1]=='n'&&arr[2]=='e') || (arr[2]=='e'&&arr[0]=='o'))
                printf("1\n");
            else if((arr[0]=='t'&&arr[1]=='w') || (arr[1]=='w'&&arr[2]=='o') || (arr[2]=='o'&&arr[0]=='t'))
                printf("2\n");
        }
        else if(len==5)
            printf("3\n");
    }
    return 0;
}
