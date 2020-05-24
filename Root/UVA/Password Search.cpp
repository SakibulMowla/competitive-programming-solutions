#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    string str,temp,ans;
    map <string,int> m;
    int n,max,i,limit;
    while(cin >> n >> str)
    {
        m.clear();
        limit = str.length()-n+1;
        for(i=0;i<limit;i++)
        {
            temp=str.substr(i,n);
            m[temp]++;
        }
        max=0;
        for(map<string,int>::iterator it=m.begin() ; it != m.end() ; it++)
        {
            if(it->second > max)
            {
                ans = it->first;
                max = it->second;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
