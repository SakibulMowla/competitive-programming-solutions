#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int i,k,test,total;
    double per;
    char s[35];
    vector<string>v;
    map<string,int>m;
    scanf("%d",&test);
    getchar();
    getchar();
    k=0;
    while(test--)
    {
        total=0;
        v.clear();
        m.clear();
        while(gets(s) && s[0])
        {
            total++;
            if(m.find(s) == m.end())
            {
                m[s] = 1;
                //v.push_back(s);
            }
            else
                m[s]++;
        }
//        sort(v.begin(),v.end());
        if(k)printf("\n");
        k=1;
        for(map<string,int>::iterator it=m.begin();it!=m.end();it++)
        {
            per=(100.0 * it->second / total);
            cout<<it->first;
            printf(" %.4lf\n",per);
        }
    }

    return 0;
}
