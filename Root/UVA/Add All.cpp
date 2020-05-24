#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    int n,i,k,sum,temp,x,y;
    priority_queue < int, vector<int> , greater<int> > pq;

    while(scanf("%d",&n) == 1 && n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&k);
            pq.push(k);
        }
        sum=0;
        while( pq.size() != 1 )
        {
            x=pq.top();
            pq.pop();
            y=pq.top();
            pq.pop();
            temp=x+y;
            cout<<temp<<endl;
            sum+=temp;
            pq.push(temp);
        }
        pq.pop();
        printf("%d\n",sum);
    }

    return 0;
}
