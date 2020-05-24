#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
    vector<string>v;
    map<string,int>m;
    char arr[205],formed[205];
    int i,j,len,len1;
    while(scanf("%s",arr) == 1)
    {
        len=strlen(arr);
        i=0;
        while(i<len)
        {
            j=0;
            for(; i<len; i++)
            {
                if(tolower(arr[i])>='a' && tolower(arr[i])<='z')
                    formed[j++]=tolower(arr[i]);
                else
                {
                    i++;
                    break;
                }
            }
            formed[j]='\0';
            len1=strlen(formed);
            if(len1>0 && m[formed]==0)
                v.push_back(formed),m[formed] = 1;
        }
    }
    sort(v.begin(),v.end());
    for(i=0; i<v.size(); i++)
        cout<<v[i]<<endl;

    return 0;
}
