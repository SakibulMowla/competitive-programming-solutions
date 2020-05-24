#include "stdio.h"
#include "string.h"
#include "string"
#include "algorithm"
#include "iostream"

using namespace std;

int arr1[30],arr2[30];

int main()
{
    string s1,s2;
    int i,k,len1,len2;
    while(cin >> s1 >> s2)
    {
        memset(arr1,0,sizeof(arr1));
        memset(arr2,0,sizeof(arr2));
        len1 = s1.size();
        len2 = s2.size();
        if(len1 != len2)
        {
            printf("NO\n");
            continue;
        }
        for(i=0;i<len1;i++)
            arr1[s1[i]-'A']++ , arr2[s2[i]-'A']++ ;
        sort(arr1,arr1+26);
        sort(arr2,arr2+26);
        k = 1;
        for(i=0;i<26;i++)
            if(arr1[i] != arr2[i])
            {
                k = 0;
                break;
            }
        if(k) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
