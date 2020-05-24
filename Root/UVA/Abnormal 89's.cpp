#include <stdio.h>
#include <string.h>
#define SZ 200010

char arr[SZ];

int is_palindrome(int len,int upto)
{
    int i,j;
    for(i=len,j=upto; i!=j && i>=0 && j<=len; i--,j++)
        if(arr[i] != arr[j])
             return 0;
    return 1;
}

int is_alindrome(int len)
{
    int i;
    for(i=0; i<len; i++)
        if(is_palindrome(i,0) && is_palindrome(len,i+1))
            return 1;
    return 0;
}

int main()
{
    int test , len;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%s",arr);
        len = strlen(arr) - 1;
        if(is_alindrome(len)) printf("alindrome\n");
        else if(is_palindrome(len,0)) printf("palindrome\n");
        else printf("simple\n");
    }

    return 0;
}
