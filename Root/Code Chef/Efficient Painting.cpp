#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"

using namespace std;

#define SZ 50+5

struct data
{
    int x1,x2,y1,y2;
    char ch;
};

vector <data> V;

char arr[SZ][SZ];
int n;

void make_white()
{
    int i,j,k;
    data u;
    u.ch = 'W';
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i][j] == 'W')
            {
                k = j;
                while(k+1 < n && arr[i][k+1] == 'W') k++;
                u.x1 = i;
                u.y1 = j;
                u.x2 = i;
                u.y2 = k;
                V.push_back(u);
                j = k;
            }
        }
    }
}

void make_black()
{
    int i,j,k;
    data u;
    u.ch = 'B';
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i][j] == 'B')
            {
                k = j;
                while(k+1 < n && arr[i][k+1] == 'B') k++;
                u.x1 = i;
                u.y1 = j;
                u.x2 = i;
                u.y2 = k;
                V.push_back(u);
                j = k;
            }
        }
    }
}

int main()
{
    int i,j,b,w;
    data u;
    b = w = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",arr[i]);
        for(j=0;j<n;j++)
            if(arr[i][j] == 'B') b++;
            else w++;
    }

    if(b > w)
    {
        u.ch = 'F';
        u.x1 = 0;
        u.y1 = 0;
        u.x2 = n-1;
        u.y2 = n-1;
        V.push_back(u);
        make_white();
    }

    else
        make_black();

    printf("%d\n",V.size());

    for(i=0;i<V.size();i++)
        printf("%d %d %d %d %c\n",V[i].x1,V[i].y1,V[i].x2,V[i].y2,V[i].ch);

    return 0;
}
