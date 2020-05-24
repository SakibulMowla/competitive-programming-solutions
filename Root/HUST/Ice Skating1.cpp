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
int n , connected[110];

void make_connection(int p)
{
    connected[p] = 1;
    int i;
    for(i=0;i<n;i++)
    {
        if(connected[i] == 0 && (V[i].x == V[p].x || V[i].y == V[p].y))
            make_connection(i);
    }
}

int main()
{
    int i,k;
    data u;
    while(scanf("%d",&n) == 1)
    {
        V.clear();
        memset(connected,0,sizeof(connected));
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&u.x,&u.y);
            V.push_back(u);
        }
        k = 0;
        for(i=0;i<n;i++)
        {
            if(connected[i] == 0)
            {
                k++;
                make_connection(i);
            }
        }
        printf("%d\n",--k);
    }

    return 0;
}
