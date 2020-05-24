#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

#define clear(a) a.clear()
#define pb push_back
#define bp pop_back

bool taken[26] , matrix[26][26];
vector <char> v , result , vertex;
map <char , int> m;
int nodes , best;

void backtrack()
{
    int i;
    if(v.size() == nodes)
    {
        int j,maxim = -1;
        for(i=0; i<nodes; i++)
            for(j=i+1; j<nodes; j++)
                if(matrix[v[i]-65][v[j]-65] && j-i > maxim)
                    maxim = j - i;

        if(maxim < best)
            result = v , best = maxim;
        return;
    }
    for(i=0; i<nodes; i++)
    {
        if( !taken[vertex[i]-65])
        {
            taken[vertex[i]-65] = 1;
            v.pb(vertex[i]);
            backtrack();
            v.bp();
            taken[vertex[i]-65] = 0;
        }
    }
}

int main()
{
    char arr[100],n;
    int i,j,k;
//    freopen("1.txt","r",stdin);
    while(scanf(" %[^\n]",arr) == 1)
    {
        if(strcmp("#",arr) == 0)break;
        memset(matrix,false,sizeof(matrix));
        memset(taken,false,sizeof(taken));
        clear(v);
        clear(m);
        clear(vertex);
        clear(result);
        char *tok = strtok(arr , ";");
        nodes = 0;
        while(tok != NULL)
        {
            n = tok[0];
            if(m.find(n) == m.end())
            {
                m[n] = n-65;
                nodes++;
                vertex.pb(n);
            }
            for(i=2; i<strlen(tok); i++)
            {
                if(m.find(tok[i]) == m.end())
                {
                    m[tok[i]] = tok[i]-65;
                    nodes++;
                    vertex.pb(tok[i]);
                }
                matrix[n-65][tok[i]-65] = matrix[tok[i]-65][n-65] = 1;
            }

            tok = strtok(NULL,";");
        }

        sort(vertex.begin(),vertex.end());
        best = INT_MAX;
        backtrack();
        for(i=0; i<result.size(); i++)
            printf("%c ",result[i]);
        printf("-> %d\n",best);
    }

    return 0;
}
