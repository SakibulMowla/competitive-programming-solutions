#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "iostream"
#include "map"

using namespace std;

char arr[100];

bool isPalindrome(int n,int m)
{
    int i,j;
    for(i=n,j=m;i<=n+(m-n)/2;i++,j--)
        if(arr[i] != arr[j])
            break;
    if(i == n + (m-n)/2 + 1) return true;
    return false;
}

int main()
{
    int i,j,k,len;
    map <string , int> m;
    string str;
    while(scanf("%s",arr) == 1)
    {
        m.clear();
        len = strlen(arr);
        k = 0;
        for(i=0;i<len;i++)
        {
            str.erase();
            for(j=i;j<len;j++)
            {
                str += arr[j];
                if(isPalindrome(i,j) && m.find(str) == m.end())
                    k++ , m[str] = 1;
            }
        }
        printf("The string '%s' contains %d palindromes.\n",arr,k);
    }

    return 0;
}
