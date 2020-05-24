#include <stdio.h>
#include <string.h>
#include <stack>
#include <iostream>

using namespace std;

int main()
{
    int t,test,i,j,k,l;
    char ch;
    stack <char> s;
    scanf("%d",&test);
    getchar();
    getchar();
    for(t=0;t<test;t++)
    {
        if(t)printf("\n");
        while(scanf("%c",&ch)==1 &&ch!='\n')
        {
            getchar();
            if(isdigit(ch))printf("%c",ch);
            if(ch=='(')
                s.push(ch);
            if(ch=='*' || ch=='/')
            {
                while(!s.empty() &&(s.top()=='*' || s.top()=='/'))
                {
                    printf("%c",s.top());
                    s.pop();
                }
                s.push(ch);
            }

            if(ch=='+' || ch=='-')
            {
                while(!s.empty() &&(s.top()=='*' || s.top()=='/' || s.top()=='+' || s.top()=='-'))
                {
                    printf("%c",s.top());
                    s.pop();
                }
                s.push(ch);
            }
            if(ch==')')
            {
                while(s.top()!='(')
                {
                    printf("%c",s.top());
                    s.pop();
                }
                s.pop();
            }
        }
        while(!s.empty())
        {
            printf("%c",s.top());
            s.pop();
        }
        printf("\n");
    }

    return 0;
}
