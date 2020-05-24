#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(int n)
{
    char arr[100];
    int i,len;
    len = sprintf(arr,"%d",n);
    for(i=0;i<len/2;i++)
        if(arr[i] != arr[len-i-1])
            break;
    if(i == len/2) return 1;
    return 0;
}

int main()
{
    int t,test,n;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        if(is_palindrome(n)) printf("Case %d: Yes\n",++t);
        else printf("Case %d: No\n",++t);
    }

    return 0;
}
