#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

int main()
{
    int t,test,i;
    vector <char> v1,v2;
    char arr[110];
    scanf("%d",&test);
    t = 0;
    while(test--)
    {
        scanf(" %[^\n]",arr);
        for(i=0;arr[i];i++)
        {
            if(arr[i] != ' ')
            v1.push_back(tolower(arr[i]));
        }
        scanf(" %[^\n]",arr);
        for(i=0;arr[i];i++)
        {
            if(arr[i] != ' ')
            v2.push_back(tolower(arr[i]));
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        if(v1 == v2) printf("Case %d: Yes\n",++t);
        else printf("Case %d: No\n",++t);
        v1.clear();
        v2.clear();
    }

    return 0;
}
