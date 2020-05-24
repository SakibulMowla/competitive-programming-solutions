#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace  std;

#define inf 1<<28
#define SZ 1010

int days[] = {0,31,59,90,120,151,181,212,243,273,304,334};

struct data
{
    int start , end , jud , hand;
};

bool comp(data p,data q)
{
    if(p.start == q.start)
    {
        if(p.end == q.end)
        {
            return p.jud < q.jud;
        }
        return p.end < q.end;
    }

    return p.start < q.start;
}

vector <data> input;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n , i ,j ,k,m,d,p,t,ans,tmp;
    data u;
    while(scanf("%d",&n) == 1)
    {
        input.clear();
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d %d",&m,&d,&p,&t);
            u.start = days[m-1] + d - t;
            u.end = days[m-1] + d - 1;
            u.jud = p;
            u.hand = p;
            input.push_back(u);
        }
        sort(input.begin(),input.end(),comp);
        ans = 0;
        input[0].hand = input[0].jud;
        for(i=0;i<n;i++)
        {
            ans += input[i].jud;
            tmp = input[i].hand;
            for(j=i+1;j<n && tmp>0;j++)
            {
                if(input[i].end < input[j].start)
                {
                    if(tmp > input[j].jud)
                    {
                        tmp = tmp - input[j].jud;
                        input[j].jud = 0;
                    }
                    else
                    {
                        input[j].jud = input[j].jud - tmp;
                        tmp = 0;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }


    return 0;
}
