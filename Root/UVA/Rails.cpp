            // 514 - Rails
#include <stdio.h>
#include <string.h>
#include <stack>
#include <iostream>
using namespace std;
int main()
{
    int i,n,num;
    stack <int> A,B;
    while(scanf("%d",&n)==1 && n)
    {
        while(scanf("%d",&num)==1)
        {
            if(num == 0)
            {
                printf("\n");
                break;
            }
            while(!A.empty())A.pop();
            while(!B.empty())B.pop();
            A.push(num);
            for(i=1;i<n;i++)
            {
                scanf("%d",&num);
                A.push(num);
            }
            i = n;
            while(i)
            {
                if(!B.empty() && B.top()==i)
                    {i--;B.pop();continue;}
                else if(A.empty())
                    break;
                else if(A.top() != i)
                    B.push(A.top());
                else i--;
                A.pop();
            }
            if(A.empty() && B.empty())
                printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
