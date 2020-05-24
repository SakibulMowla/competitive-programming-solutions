#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t,n,test,num,pos;
    map <int , int> m;
    map <int , int> count;
    map <int , int> :: iterator it;
    while(scanf("%d",&test) == 1)
    {
        m.clear();
        count.clear();
        for(t=1; t<=test; t++)
        {
            scanf("%d",&n);
            m[n] = t;
            count[n]++;
        }

        it=m.begin();
        num=it->first;
        pos=it->second;

        if(count[num] == 1)
        {
            printf("%d\n",pos);
        }
        else
            printf("Still Rozdil\n");
    }

    return 0;
}
