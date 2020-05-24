#include<stdio.h>
#include<string.h>

int main(void)
{
    int i,j,k,l,len,flag;
    char arr[100],rev[100];
    while(scanf("%s",arr)==1)
    {
        flag=0;
        len=strlen(arr);
        if(len==1)
        {
            if(arr[0]=='A'|| arr[0]=='H'|| arr[0]=='I'|| arr[0]=='M'|| arr[0]=='O'|| arr[0]=='T'|| arr[0]=='U'|| arr[0]=='V'|| arr[0]=='W'|| arr[0]=='X'|| arr[0]=='Y'|| arr[0]=='1'|| arr[0]=='8')
                printf("%s -- is a mirrored palindrome.\n\n",arr);
            else
                printf("%s -- is a regular palindrome.\n\n",arr);
            continue;
        }

        for(i=0,j=len-1; i<len; i++,j--)
        {
            if(arr[i]!=arr[j])
                flag++;
        }

        for(i=0,j=len-1; i<len; i++,j--)
        {
            if(arr[i]=='A')
                rev[j]='A';
            else if(arr[i]=='E')
                rev[j]='3';
            else if(arr[i]=='H')
                rev[j]='H';
            else if(arr[i]=='I')
                rev[j]='I';
            else if(arr[i]=='J')
                rev[j]='L';
            else if(arr[i]=='L')
                rev[j]='J';
            else if(arr[i]=='M')
                rev[j]='M';
            else if(arr[i]=='O')
                rev[j]='O';
            else if(arr[i]=='S')
                rev[j]='2';
            else if(arr[i]=='T')
                rev[j]='T';
            else if(arr[i]=='U')
                rev[j]='U';
            else if(arr[i]=='V')
                rev[j]='V';
            else if(arr[i]=='W')
                rev[j]='W';
            else if(arr[i]=='X')
                rev[j]='X';
            else if(arr[i]=='Y')
                rev[j]='Y';
            else if(arr[i]=='Z')
                rev[j]='5';
            else if(arr[i]=='1')
                rev[j]='1';
            else if(arr[i]=='2')
                rev[j]='S';
            else if(arr[i]=='3')
                rev[j]='E';
            else if(arr[i]=='5')
                rev[j]='Z';
            else if(arr[i]=='8')
                rev[j]='8';

        }
        rev[i]='\0';
        if(strcmp(rev,arr)!=0 && flag!=0)
            printf("%s -- is not a palindrome.\n\n",arr);
        else if(strcmp(rev,arr)!=0 && flag==0)
            printf("%s -- is a regular palindrome.\n\n",arr);
        else if(strcmp(rev,arr)==0 && flag!=0)
            printf("%s -- is a mirrored string.\n\n",arr);
        else if(strcmp(rev,arr)==0 && flag==0)
            printf("%s -- is a mirrored palindrome.\n\n",arr);
    }

    return 0;
}
