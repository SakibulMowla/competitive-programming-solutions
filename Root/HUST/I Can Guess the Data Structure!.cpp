#include "stdio.h"
#include "string.h"
#include "string"
#include "stack"
#include "queue"
#include "algorithm"
#include "iostream"
#include "math.h"
#include "map"
#include "vector"

using namespace std;

struct data
{
    int x,y;
};

stack <int> S;
queue <int> Q;
priority_queue <int> PQ;
vector <data> input;

int main()
{
    int st,qu,pqu,i,j,k,n,m;
    data u;
    while(scanf("%d",&n) == 1)
    {
        input.clear();
        while(!S.empty()) S.pop();
        while(!Q.empty()) Q.pop();
        while(!PQ.empty()) PQ.pop();
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&u.x,&u.y);
            input.push_back(u);
        }
        st = qu = pqu  = 0;
        for(i=0;i<n;i++)
        {
            if(input[i].x == 1) S.push(input[i].y);
            else
            {
                if(S.empty()) break;
                m = S.top();
                S.pop();
                if(m != input[i].y) break;
            }
        }
        if(i == n) st = 1;

        for(i=0;i<n;i++)
        {
            if(input[i].x == 1) Q.push(input[i].y);
            else
            {
                if(Q.empty()) break;
                m = Q.front();
                Q.pop();
                if(m != input[i].y) break;
            }
        }
        if(i == n) qu = 1;

        for(i=0;i<n;i++)
        {
            if(input[i].x == 1) PQ.push(input[i].y);
            else
            {
                if(PQ.empty()) break;
                m = PQ.top();
                PQ.pop();
                if(m != input[i].y) break;
            }
        }
        if(i == n) pqu = 1;

        if(st + qu + pqu > 1) printf("not sure\n");
        else if(st == 1) printf("stack\n");
        else if(qu == 1) printf("queue\n");
        else if(pqu == 1) printf("priority queue\n");
        else printf("impossible\n");
    }
    return 0;
}
