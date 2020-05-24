#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n,m,i,j,test;
    char arr[1000];
    stack <char> s;
    scanf("%d",&test);
    while(test--)
    {
        scanf(" %[^\n]",arr);
        for(i=0;i<strlen(arr);i++)
        {
            if(arr[i] >= 'a' && arr[i] <= 'z')
                printf("%c",arr[i]);
            if(arr[i]=='+' || arr[i]=='-' || arr[i]=='*' || arr[i]=='/' || arr[i]=='^')
                s.push(arr[i]);
            if(arr[i] == ')')
            {
                printf("%c",s.top());
                s.pop();
            }
        }
        printf("\n");
    }

    return 0;
}
