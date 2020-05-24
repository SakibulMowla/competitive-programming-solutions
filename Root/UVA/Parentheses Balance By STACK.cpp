#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int top;
char arr[200],str[200];
char ch;

void push(char item)
{
    str[top++]=item;
    return;
}

int pop(void)
{
    --top;
    if(top<0)
        return 0;

    else if(ch == ']' && str[top]!='[')
        return 0;

    else if(ch == ')' && str[top]!='(')
        return 0;

    return 1;
}

int main()
{
    int test,ans,flag;
    scanf("%d",&test);
    getchar();
    while(test--)
    {
        gets(arr);
        top=0;
        flag=1;

        for(int i=0; i<strlen(arr); i++)
        {
            if(arr[i]==']' || arr[i]==')')
            {
                ch=arr[i];
                ans=pop();
                if(ans==0)
                {
                    printf("No\n");
                    flag=0;
                    break;
                }
            }

            else
                push(arr[i]);
        }

        if(flag==0)
            continue;
        if(top==0)
            printf("Yes\n");
        else
            printf("No\n");

    }

    return 0;
}
