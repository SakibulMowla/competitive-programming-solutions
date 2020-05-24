#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

char arr[35];
int n,len;
vector <char> result;

void backtrack(int pos)
{
    int i;
    if(result.size() == n)
    {
        for(i=0; i<n; i++)
            cout<<result[i];
        printf("\n");
        return;
    }
    for(i=pos; i<len; )
    {
        result.push_back(arr[i]);
        backtrack(i+1);
        i++;
        while(arr[i] == arr[i-1])
            i++;
        result.pop_back();
    }
}

int main()
{
    while(scanf("%s %d",arr,&n) == 2)
    {
        len = strlen(arr);
        sort(arr,arr+len);
        backtrack(0);
    }
    return 0;
}
