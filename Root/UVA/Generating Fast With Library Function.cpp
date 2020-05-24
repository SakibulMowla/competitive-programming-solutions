#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
    int n,i,len;
    char arr[20];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",arr);
        len=strlen(arr);
        sort(arr,arr+len);
        do
        {
            printf("%s\n",arr);
        }while( next_permutation(arr,arr+len) );
        printf("\n");
    }
    return 0;
}
