#include "stdio.h"
#include "string.h"
#include "iostream"
#include "list"

using namespace std;

int main()
{
    list <char> beiju;
    list <char>::iterator it;

    int i,len;
    char arr[100010];

    while(scanf("%s",arr) == 1)
    {
        beiju.clear();
        it = beiju.begin();

        len = strlen(arr);
        for(i=0;i<len;i++)
        {
            if(arr[i] == '[')
                it = beiju.begin();
            else if(arr[i] == ']')
                it = beiju.end();
            else
                beiju.insert(it , arr[i]);
        }

        for(it=beiju.begin();it!=beiju.end();it++)
            printf("%c",*it);

        printf("\n");
    }
}
