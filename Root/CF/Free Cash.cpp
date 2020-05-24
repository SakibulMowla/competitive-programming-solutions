#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    map <int , int> m;
    map <int , int> :: iterator it;
    int i,count,n,u,h,min;
    while(scanf("%d",&n) == 1)
    {
        m.clear();
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&h,&min);
            u = (h*100) + min;
            m[u] = m[u] + 1;
        }
        count = 0;
        for(it=m.begin();it!=m.end();it++)
        {
            if(it->second > count)
                count = it->second;
        }
        printf("%d\n",count);
    }

    return 0;
}
