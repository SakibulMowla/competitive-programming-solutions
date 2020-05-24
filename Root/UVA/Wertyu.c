#include<stdio.h>
#include<string.h>

int main()
{
    int i,len;
    char arr[1000];
    while(gets(arr))
    {
        len=strlen(arr);
        for(i=0;i<len;i++)
        {
            if(arr[i]==' ')
                printf(" ");
            else if(arr[i]=='1')
            printf("`");
            else if(arr[i]=='2')
            printf("1");
            else if(arr[i]=='3')
            printf("2");
            else if(arr[i]=='4')
            printf("3");
            else if(arr[i]=='5')
            printf("4");
            else if(arr[i]=='6')
            printf("5");
            else if(arr[i]=='7')
            printf("6");
            else if(arr[i]=='8')
            printf("7");
            else if(arr[i]=='9')
            printf("8");
            else if(arr[i]=='0')
            printf("9");
            else if(arr[i]=='-')
            printf("0");
            else if(arr[i]=='=')
            printf("-");
            else if(arr[i]=='W')
            printf("Q");
            else if(arr[i]=='E')
            printf("W");
            else if(arr[i]=='R')
            printf("E");
            else if(arr[i]=='T')
            printf("R");
            else if(arr[i]=='Y')
            printf("T");
            else if(arr[i]=='U')
            printf("Y");
            else if(arr[i]=='I')
            printf("U");
            else if(arr[i]=='O')
            printf("I");
            else if(arr[i]=='P')
            printf("O");
            else if(arr[i]=='[')
            printf("P");
            else if(arr[i]==']')
            printf("[");
            else if(arr[i]=='\\')
            printf("]");
            else if(arr[i]=='S')
            printf("A");
            else if(arr[i]=='D')
            printf("S");
            else if(arr[i]=='F')
            printf("D");
            else if(arr[i]=='G')
            printf("F");
            else if(arr[i]=='H')
            printf("G");
            else if(arr[i]=='J')
            printf("H");
            else if(arr[i]=='K')
            printf("J");
            else if(arr[i]=='L')
            printf("K");
            else if(arr[i]==';')
            printf("L");
            else if(arr[i]==39)
            printf(";");
            else if(arr[i]=='X')
            printf("Z");
            else if(arr[i]=='C')
            printf("X");
            else if(arr[i]=='V')
            printf("C");
            else if(arr[i]=='B')
            printf("V");
            else if(arr[i]=='N')
            printf("B");
            else if(arr[i]=='M')
            printf("N");
            else if(arr[i]==',')
            printf("M");
            else if(arr[i]=='.')
            printf(",");
            else if(arr[i]=='/')
            printf(".");
        }
        printf("\n");
    }
    return 0;
}
