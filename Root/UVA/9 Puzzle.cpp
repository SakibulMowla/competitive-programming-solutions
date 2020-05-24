#include "stdio.h"
#include "string.h"
#include "string"
#include "map"
#include "queue"
#include "iostream"
using namespace std;

map <string , int> dist;
map <string , string> par , move;
queue <string> Q;
string target;

void BFS()
{
    dist[target] = 0;
    Q.push(target);
    int i,j;
    string ch;
    string u,v;

    while( !Q.empty() )
    {
        u = Q.front();
        Q.pop();
        for(i=0; i<3; i++)
        {
            v = u;
            if(i == 0) v[0] = u[1] , v[1] = u[2] , v[2] = u[0];
            else if(i == 1) v[3] = u[4] , v[4] = u[5] , v[5] = u[3];
            else v[6] = u[7] , v[7] = u[8] , v[8] = u[6];
            if(dist.find(v) == dist.end())
            {
                dist[v] = dist[u] + 1;
                Q.push(v);
                par[v] = u;
                ch = string(1,'H') + string(1,i + '1');
                move[v] = ch;
            }
        }
        for(i=0;i<3;i++)
        {
            v = u;
            if(i == 0) v[0] = u[6] , v[3] = u[0] , v[6] = u[3];
            else if(i == 1) v[1] = u[7] , v[4] = u[1] , v[7] = u[4];
            else v[2] = u[8] , v[5] = u[2] , v[8] = u[5];
            if(dist.find(v) == dist.end())
            {
                dist[v] = dist[u] + 1;
                Q.push(v);
                par[v] = u;
                ch = string(1,'V') + string(1,i + '1');
                move[v] = ch;
            }
        }
    }
}

string print;

void PathPrint(string str)
{
    print = "";
    while(str != target)
    {
        print += move[str];
        str = par[str];
    }
    printf("%s\n",print.c_str());
}

int main()
{
    target = "123456789";
    BFS();
    int i,j;
    string str;
    while(true)
    {
        str.clear();
        for(i=0; i<9; i++)
        {
            scanf("%d",&j);
            if(j == 0) return 0;
            str += j + '0';
        }
        if(str == target) printf("0\n");
        else if(dist.find(str) != dist.end())
        {
            printf("%d ",dist[str]);
            PathPrint(str);
        }
        else printf("Not solvable\n");
    }

    return 0;
}
