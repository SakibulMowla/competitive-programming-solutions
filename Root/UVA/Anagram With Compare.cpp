#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

bool comp(const char &a,const char &b)
{
    int v = tolower(a) - tolower(b);
    return v ? v < 0 : a < b;
}

int main()
{
    int n;
    char arr[1000];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",arr);
        sort(arr,arr+strlen(arr),comp);
        do
            printf("%s\n",arr);
        while(next_permutation(arr,arr+strlen(arr),comp));
    }

    return 0;
}
