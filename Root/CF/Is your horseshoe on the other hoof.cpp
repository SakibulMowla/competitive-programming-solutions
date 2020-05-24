#include <cstdio>
#include <map>
#include <iostream>

using namespace std;

int main()
{
    int s[5],count,i;
    map <int ,int > m;
    while(scanf("%d %d %d %d",&s[0],&s[1],&s[2],&s[3]) == 4)
    {
        m.clear();
        count=0;
        for(i=0;i<4;i++)
        {
            m[s[i]]++;
            if(m[s[i]] == 1)
                count++;
        }
        printf("%d\n",4-count);
    }

    return 0;
}
