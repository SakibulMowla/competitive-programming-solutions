#include "stdio.h"
#include "string.h"
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

#define SZ 30
bool avail[SZ] , constraint[SZ][SZ];
char input[SZ] , output[SZ];
int out_len;

bool check(int len,int now)
{
    for(int i=0; i<len; i++)
        if(constraint[now][output[i]-'a'] == true)
            return false;
    return true;
}

void backtrack(int len)
{
    int i;
    if(len == out_len)
    {
        for(i=0; i<out_len; i++)
            printf("%c",output[i]);
        printf("\n");
        return;
    }
    for(i=0; i<out_len; i++)
    {
        if(avail[i] && check(len,input[i]-'a'))
        {
            output[len] = input[i];
            avail[i] = false;
            backtrack(len+1);
            avail[i] = true;
        }
    }
}

int main()
{
    int i,blank;
    char arr[1000],a,b;
    blank  = 0;
//    freopen("1.txt","r",stdin);
    while(gets(arr))
    {
        memset(constraint,false,sizeof(constraint));
        memset(avail,true,sizeof(avail));
        out_len = 0;

        for(i=0; arr[i]; i++)
            if(arr[i] >= 'a' && arr[i] <= 'z')
                input[out_len++] = arr[i];

        sort(input,input+out_len);

        gets(arr);
        for(i=0; arr[i]; i++)
        {
            if(arr[i] >= 'a' && arr[i] <= 'z')
            {
                a = arr[i];
                i++;
                while(arr[i] > 'z' || arr[i] < 'a')i++;
                b = arr[i];
                constraint[a-'a'][b-'a'] = true;
            }
        }
        if(blank)printf("\n");
        blank = 1;
        backtrack(0);
    }

    return 0;
}
