#include "stdio.h"
#include "iostream"
using namespace std;
char arr[10];

int main()
{
    int n,i,j,k,x;
    while(cin >> n)
    {
        x = 0;
        while(n--)
        {
            scanf(" %s",arr);
            if(arr[1] == '+') x++;
            else x--;
        }
        printf("%d\n",x);
    }

    return 0;
}
