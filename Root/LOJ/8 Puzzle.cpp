#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "iostream"
using namespace std;
#define X first
#define Y second

int col[6000000];

int m[3][3];
int t[3][3];

int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};

typedef pair <int , int> pii;
pii rp[10];

int fail;

void dfs(int b[3][3],int n,int m,int step,int man)
{
//    if(man >= 20) return;
    printf("man = %d f = %d\n",man,fail);
    col[man] = step;

    int i,j,k,p,q,u,v,tmp;

    for(i=0;i<4;i++)
    {
//        printf("yes\n");
        u = n + x[i];
        v = m + y[i];
        if(u>=0 && v >= 0 && u < 3 && v < 3)
        {
//            printf("yes1\n");
            tmp = b[n][m];
            b[n][m] = b[u][v];
            b[u][v] = tmp;
            tmp = 0;
            for(j=0;j<3;j++)
                for(k=0;k<3;k++)
                {
                    tmp += abs(j-rp[ b[j][k] ].X) + abs(k-rp[ b[j][k] ].Y);
                }
//            tmp += step;
//            printf("tmp : %d\n",tmp);
            if(col[tmp] == -1)
                dfs(b, u, v, step+1, tmp);
            else fail++;
        }
    }
}

int main()
{
    memset(col,-1,sizeof(col));
    m[0][0] = 1; m[0][1] = 2; m[0][2] = 3; m[1][0] = 4; m[1][1] = 5; m[1][2] = 6; m[2][0] = 7;m[2][1] = 8; m[2][2] = 0;
    rp[1] = make_pair(0,0);
    rp[2] = make_pair(0,1);
    rp[3] = make_pair(0,2);
    rp[4] = make_pair(1,0);
    rp[5] = make_pair(1,1);
    rp[6] = make_pair(1,2);
    rp[7] = make_pair(2,0);
    rp[8] = make_pair(2,1);
    rp[0] = make_pair(2,2);
    fail = 0;
    dfs(m, 2, 2, 0, 0);
}
