#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

int matrix[15][15] , gone[15];
int flag , nodes , length;
vector <int> result;

void backtrack(int indx)
{
    int i;
    if(result.size() == length+1)
    {
        flag = 1;
        printf("(");
        cout<<result[0];
        for(i=1;i<=length;i++)
            cout<<","<<result[i];
        printf(")");
        printf("\n");
        return;
    }
    for(i=1;i<=nodes;i++)
    {
        if(matrix[indx][i] == 1 && gone[i]== 0)
        {
            result.push_back(i); gone[i] = 1;
            backtrack(i);
            result.pop_back(); gone[i] = 0;
        }
    }
}

int main()
{
    int test=0,i,j,check;
    while(scanf("%d %d",&nodes,&length)!=EOF)
    {
        result.clear();
        memset(matrix , 0 ,sizeof(matrix));
        memset(gone , 0 ,sizeof(gone));
        if(test)printf("\n");
        ++test;
        for(i=1;i<=nodes; i++)
        {
            for(j=1;j<=nodes; j++)
            {
                scanf("%d",&check);
                matrix[i][j] = check;
            }
        }
        result.push_back(1);
        gone[1] = 1;
        flag = 0;
        backtrack(1);
        if(flag == 0)
            printf("no walk of length %d\n",length);
        scanf("%d",&check);
    }

    return 0;
}
