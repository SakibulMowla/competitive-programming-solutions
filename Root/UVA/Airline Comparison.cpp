#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

using namespace std;

#define inf 1<<28
#define SZ 300

int matrix1[SZ][SZ] , matrix2[SZ][SZ];

map<char ,int> M;

void init()
{
    M.clear();
    int i,j;
    for(i=0; i<SZ; i++)
    {
        for(j=i+1; j<SZ; j++)
            matrix1[i][j] = matrix1[j][i] = matrix2[i][j] = matrix2[j][i] = inf;
        matrix1[i][i] = matrix2[i][i] = 0;
    }
}

int main()
{
    int test,i,j,k,nodes,n,m;
    char ch1,ch2;
    bool flag;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        init();
        nodes = 0;
        flag = true;
        for(i=0; i<n; i++)
        {
            scanf(" %c %c",&ch1,&ch2);
            ch1 = tolower(ch1);
            ch2 = tolower(ch2);
            if(M.find(ch1) == M.end()) M[ch1] = nodes++;
            if(M.find(ch2) == M.end()) M[ch2] = nodes++;
            matrix1[ M[ch1] ] [ M[ch2] ] = matrix1 [ M[ch2] ] [ M[ch1] ] = 1;
        }

        for(i=0; i<nodes; i++)
        for(j=0; j<nodes; j++)
        for(k=0; k<nodes; k++)
        matrix1[i][j] = min(matrix1[i][j],matrix1[i][k]+matrix1[k][j]);

        scanf("%d",&m);
        for(i=0; i<m; i++)
        {
            scanf(" %c %c",&ch1,&ch2);
            ch1 = tolower(ch1);
            ch2 = tolower(ch2);
            if(M.find(ch1) == M.end()) M[ch1] = nodes++;
            if(M.find(ch2) == M.end()) M[ch2] = nodes++;
            matrix2[ M[ch1] ] [ M[ch2] ] = matrix2  [ M[ch2] ] [ M[ch1] ] = 1;
        }

        for(i=0; i<nodes; i++)
        for(j=0; j<nodes; j++)
        for(k=0; k<nodes; k++)
        matrix2[i][j] = min(matrix2[i][j],matrix2[i][k]+matrix2[k][j]);

        for(i=0; i<nodes; i++)
        {
            for(j=i+1; j<nodes; j++)
            {
                if((matrix1[i][j] < inf && matrix2[i][j] == inf) || (matrix2[i][j] < inf && matrix1[i][j] == inf))
                {
                    flag = false;
                    break;
                }
            }
            if( !flag ) break;
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
        if(test) printf("\n");
    }
    return 0;
}
