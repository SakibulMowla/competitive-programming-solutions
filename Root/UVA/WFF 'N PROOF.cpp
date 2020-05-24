#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

int main()
{
    int i,j,k,l,not_cnt;
    char arr[100];
    stack <char> operands, OPERATORS;
    string output,a,b;
    while(scanf("%s",arr) == 1)
    {
        if(strcmp(arr,"0") == 0)break;
        while( !operands.empty() )operands.pop();
        while( !OPERATORS.empty() )OPERATORS.pop();
        output.clear();
        not_cnt = 0;
        l = strlen(arr);
        for(i=0;i<l;i++)
        {
            if(arr[i] == 'N')not_cnt++;
            else
            {
                if(arr[i] == 'K' || arr[i] == 'A' || arr[i] == 'C' || arr[i] == 'E')
                    OPERATORS.push(arr[i]);
                else
                    operands.push(arr[i]);
            }
        }
        if( operands.empty() )
        {
            printf("no WFF possible\n");
            continue;
        }
        output = operands.top();
        operands.pop();
        while( !operands.empty() && !OPERATORS.empty() )
        {
            a = OPERATORS.top();
            b = operands.top();
            output = a + b + output;
            operands.pop();
            OPERATORS.pop();
        }
        while(not_cnt--)
        {
            output = "N" + output;
        }
        cout << output << endl;
    }

    return 0;
}
