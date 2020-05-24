#include "stdio.h"
#include "iostream"
using namespace std;

const int inf = 1e9;
#define SZ 310

bool mark[SZ];
int matrix[SZ][SZ];

void init(int n)
{
    int i, j;

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
            matrix[i][j] = matrix[j][i] = inf;
        mark[i] = matrix[i][i] = 0;
    }

    return ;
}

void update(int node,int n)
{
    int i, j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(matrix[i][j] > matrix[i][node] + matrix[node][j])
                matrix[i][j] = matrix[i][node] + matrix[node][j];
}

int main()
{
//    freopen("1.txt","r",stdin);
    bool blank = false;

    int n, m, q, i, j, k, l, test=0;

    while(scanf("%d %d %d",&n,&m,&q) == 3)
    {
        if(n == 0 && m == 0 && q == 0)
            break;

        if(blank) printf("\n");
        else blank = true;
        printf("Case %d:\n",++test);

        init(n);

        for(i=0; i<m; i++)
        {
            scanf("%d %d %d",&j,&k,&l);
            if(matrix[j][k] > l)
                matrix[j][k] = l;
        }

        while(q--)
        {
            scanf("%d",&i);
            if(!i)
            {
                scanf("%d",&j);
                if(mark[j]) printf("ERROR! At point %d\n",j);
                else
                {
                    mark[j] = 1;
                    update(j, n);
                }
            }
            else
            {
                scanf("%d %d",&j,&k);
                if(!mark[j] || !mark[k]) printf("ERROR! At path %d to %d\n",j,k);
                else
                {
                    if(matrix[j][k] >= inf) printf("No such path\n");
                    else printf("%d\n",matrix[j][k]);
                }
            }
        }
    }

    return 0;
}
