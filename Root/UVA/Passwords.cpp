#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

vector <string> words , output;
int word_cnt , rule_cnt , out_len;
char arr[300];
string num[10] = {"0","1","2","3","4","5","6","7","8","9"};

void backtrack(int n)
{
    int i;
    if(n == out_len)
    {
        for(i=0; i<out_len; i++)
            cout<<output[i];
        printf("\n");
        return;
    }
    if(arr[n] == '#')
        for(i=0; i<word_cnt; i++)
        {
            output.push_back(words[i]);
            backtrack(n+1);
            output.pop_back();
        }
    else
        for(i=0; i<=9; i++)
        {
            output.push_back(num[i]);
            backtrack(n+1);
            output.pop_back();
        }
}

int main()
{
    int i;
//    freopen("1.txt","r",stdin);
    while(scanf("%d",&word_cnt) == 1)
    {
        words.clear();
        for(i=0; i<word_cnt; i++)
        {
            scanf(" %[^\n]",arr);
            words.push_back(arr);
        }
        printf("--\n");
        scanf("%d",&rule_cnt);
        for(i=0; i<rule_cnt; i++)
        {
            scanf(" %[^\n]",arr);
            out_len = strlen(arr);
            backtrack(0);
        }
    }

    return 0;
}
