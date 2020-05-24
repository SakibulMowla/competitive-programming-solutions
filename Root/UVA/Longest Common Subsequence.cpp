#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define N 1010

int str[N][N];

int main()
{
    int i,j,len1,len2;
    string arr1,arr2;
    while(getline(cin,arr1) && getline(cin,arr2))
    {
        len1=arr1.length();
        len2=arr2.length();
        for(i=1;i<=len1;i++)
        {
            for(j=1;j<=len2;j++)
            {
                if(arr1[i-1]==arr2[j-1])
                    str[i][j]=str[i-1][j-1]+1;
                else
                    str[i][j]=max(str[i][j-1],str[i-1][j]);
            }
        }
        printf("%d\n",str[len1][len2]);
    }

    return 0;
}
