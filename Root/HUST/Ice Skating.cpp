#include "stdio.h"
#include "string.h"
#include "string"
#include "map"
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

typedef pair <int ,int> pii;
#define MP(a,b) make_pair(a,b)
map <pii,int> M;

struct data
{
    int x,y;
};

vector <data> V;
vector <int> num;

int main()
{
    int i,j,k,n,m,total,needed;
    data u;
    while(scanf("%d",&n) == 1)
    {
        V.clear();
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&u.x,&u.y);
            V.push_back(u);
        }
        total = needed = 0;
        M.clear();
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(V[i].x == V[j].x || V[i].y == V[j].y) continue;
                k = V[i].x;
                m = V[j].y;
                if(M.find(MP(k,m)) != M.end())
                {
                    M[MP(k,m)]++;
                }
                else
                    M[MP(k,m)] = 1;
                k = V[j].x;
                m = V[i].y;
                if(M.find(MP(k,m)) != M.end())
                {
                    M[MP(k,m)]++;
                }
                else
                    M[MP(k,m)] = 1;
                total += 2;
            }
        }
        num.clear();
        for(map <pii,int>::iterator it = M.begin();it!=M.end();it++)
        {
            num.push_back(it->second);
        }
        sort(num.rbegin(),num.rend());
        needed = total / 2;
        total = k = 0;
        for(i=0;i<num.size() && total < needed;i++)
        {
            total += num[i];
            k++;
        }
        printf("%d\n",k);
    }

    return 0;
}
