#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

int indx = 0;
char pqrst[4000][6];
vector <char> v;

void backtrack()
{
    int i;
    if(v.size() == 5)
    {
        for(i=0;i<5;i++)
            pqrst[indx][i] = v[i];
        indx++;
        return;
    }
    for(i=0;i<2;i++)
    {
        if(i==0) v.push_back('0');
        else v.push_back('1');
        backtrack();
        v.pop_back();
    }
}

int main()
{
    backtrack();
    int i,j,k,len;
    stack <char> s;
    char arr[100] , a , b;
    while(scanf("%s",arr) == 1)
    {
        if(strcmp(arr,"0") == 0)break;
        len = strlen(arr);
        while( !s.empty() ) s.pop();
        k = 1;
        for(i=0;i<32;i++)
        {
            while( !s.empty() ) s.pop();
            for(j=len-1;j>=0;j--)
            {
                if(arr[j] == 'p')s.push(pqrst[i][0]);
                if(arr[j] == 'q')s.push(pqrst[i][1]);
                if(arr[j] == 'r')s.push(pqrst[i][2]);
                if(arr[j] == 's')s.push(pqrst[i][3]);
                if(arr[j] == 't')s.push(pqrst[i][4]);
                if(arr[j] == 'N')
                {
                    a = s.top();
                    s.pop();
                    if(a == '0')s.push('1');
                    if(a == '1')s.push('0');
                }
                if(arr[j] == 'K')
                {
                    a = s.top();s.pop();
                    b = s.top();s.pop();
                    if(a == '0' && b == '0') s.push('0');
                    if(a == '1' && b == '0') s.push('0');
                    if(a == '0' && b == '1') s.push('0');
                    if(a == '1' && b == '1') s.push('1');
                }
                if(arr[j] == 'A')
                {
                    a = s.top();s.pop();
                    b = s.top();s.pop();
                    if(a == '0' && b == '0') s.push('0');
                    if(a == '1' && b == '0') s.push('1');
                    if(a == '0' && b == '1') s.push('1');
                    if(a == '1' && b == '1') s.push('1');
                }
                if(arr[j] == 'C')
                {
                    a = s.top();s.pop();
                    b = s.top();s.pop();
                    if(a == '0' && b == '0') s.push('1');
                    if(a == '1' && b == '0') s.push('1');
                    if(a == '0' && b == '1') s.push('0');
                    if(a == '1' && b == '1') s.push('1');
                }
                if(arr[j] == 'E')
                {
                    a = s.top();s.pop();
                    b = s.top();s.pop();
                    if(a == '0' && b == '0') s.push('1');
                    if(a == '1' && b == '0') s.push('0');
                    if(a == '0' && b == '1') s.push('0');
                    if(a == '1' && b == '1') s.push('1');
                }
            }
            if(s.size() == 1 && s.top() == '1')
                continue;
            else
            {
                k = 0;
                break;
            }
        }
        if(k) printf("tautology\n");
        else printf("not\n");
    }
    return 0;
}
