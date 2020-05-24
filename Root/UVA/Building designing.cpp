#include "stdio.h"
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

enum {red,blue};

struct data
{
    int height,col;
};

bool comp(data p,data q)
{
    return p.height > q.height;
}

vector <data> building;

int main()
{
    int i,j,n,now,cnt,p;
    data v;
    while(scanf("%d",&p) == 1)
    {
        while(p--)
        {
            scanf("%d",&n);
            building.clear();
            for(i=0; i<n; i++)
            {
                scanf("%d",&j);
                if(j < 0) v.col = red , j *= -1;
                else v.col = blue;
                v.height = j;
                building.push_back(v);
            }
            sort(building.begin(),building.end(),comp);
            cnt = 0;
            if(building.size()) now = building[0].col , cnt++;
            for(i=1; i<n; i++)
            {
                if(building[i].col != now)
                    cnt++ , now = building[i].col;
            }
            printf("%d\n",cnt);
        }
    }

    return 0;
}
