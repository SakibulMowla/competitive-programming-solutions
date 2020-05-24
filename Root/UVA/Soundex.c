#include<stdio.h>
#include<string.h>

int main()
{
    int i,l,c;
    char arr[20];
    while(scanf("%s",arr)==1)
    {
        c=0;
        l=strlen(arr);
        for(i=0; i<l; i++)
        {
            if(arr[i]=='B' ||arr[i]=='F' ||arr[i]=='P' ||arr[i]=='V')
            {
                if(c!=1)
                    printf("1");
                c=1;
            }
            else if(arr[i]=='C' ||arr[i]=='G' ||arr[i]=='J' ||arr[i]=='K' ||arr[i]=='Q' ||arr[i]=='S' ||arr[i]=='X' ||arr[i]=='Z' )
            {
                if(c!=2)
                    printf("2");
                c=2;
            }
            else if(arr[i]=='D' ||arr[i]=='T')
            {
                if(c!=3)
                    printf("3");
                c=3;
            }
            else if(arr[i]=='L')
            {
                if(c!=4)
                    printf("4");
                c=4;
            }
            else if(arr[i]=='M' ||arr[i]=='N')
            {
                if(c!=5)
                    printf("5");
                c=5;
            }
            else if(arr[i]=='R')
            {
                if(c!=6)
                    printf("6");
                c=6;
            }
            else
                c=arr[i];
        }
        printf("\n");
    }

    return 0;
}
