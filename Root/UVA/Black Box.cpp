#include <stdio.h>
#include <string.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int test,n,m,i,j,cnt;
    queue <int> add,get;
    priority_queue <int , vector <int> , greater <int> > mini;
    priority_queue <int> maxi;
    scanf("%d",&test);
    while(test--)
    {
        while( !add.empty() )add.pop();
        while( !get.empty() )get.pop();
        while( !mini.empty() )mini.pop();
        while( !maxi.empty() )maxi.pop();
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            add.push(j);
        }
        for(i=0;i<m;i++)
        {
            scanf("%d",&j);
            get.push(j);
        }
        cnt = 0;
        while( !add.empty() )
        {
            if(!mini.empty() && add.front() > maxi.top())//making sure that mini's elements are always greater than maxi's
                mini.push(add.front());
            else
                maxi.push(add.front());
            add.pop();
            while( !get.empty() && mini.size() + maxi.size() == get.front())
            {
                while(maxi.size() != cnt)
                {
                    if(maxi.size() < cnt)
                    {
                        maxi.push(mini.top());
                        mini.pop();
                    }
                    else if(maxi.size() > cnt)
                    {
                        mini.push(maxi.top());
                        maxi.pop();
                    }
                }
                cout << mini.top() << endl;
                cnt++;
                get.pop();
            }
        }
        if(test) printf("\n");
    }

    return 0;
}
