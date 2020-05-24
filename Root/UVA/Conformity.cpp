#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

#define pb push_back

using namespace std;

int main()
{
    int test,i,j,k,l,max,num,ans;
    char arr[20];
    vector <int> v;
    map <string,int> m;
    map <string,int> :: iterator it;
    string str;
    while(scanf("%d",&test) == 1 && test)
    {
        m.clear();
        max=0;
        while(test--)
        {
            v.clear();
            for(i=0;i<5;i++)
            {
                scanf("%d",&num);
                v.pb(num);
            }
            sort(v.begin(),v.end());
            str.erase(0);
            for(i=0;i<5;i++)
            {
                sprintf(arr,"%d",v[i]);
                str+=arr;
            }
            if(m.find(str) == m.end())
                m[str] = 1;
            else
                m[str]++;
            if(m[str] > max)
                max=m[str];
        }
        ans=0;
        for(it=m.begin();it!=m.end();it++)
            if(it->second == max)
                ans+=it->second;

        printf("%d\n",ans);
    }

    return 0;
}
