#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

int matrix[10][10] , gone[10][10];
vector <int> result;

void backtrack(int n)
{
    int i;
    if(result.size() == 9)
    {
        for(i=0;i<9;i++)
            cout<<result[i];
        printf("\n");
        return;
    }
    for(i=1;i<=5;i++)
    {
        if(matrix[n][i] == 1 && gone[n][i] == 0 && gone[i][n] == 0)
        {
            result.push_back(i); gone[n][i] = 1;
            backtrack(i);
            gone[n][i] = 0; result.pop_back();
        }
    }
}

int main()
{
    matrix[1][2] = 1;
    matrix[1][5] = 1;
    matrix[1][3] = 1;
    matrix[2][1] = 1;
    matrix[2][3] = 1;
    matrix[2][5] = 1;
    matrix[3][1] = 1;
    matrix[3][2] = 1;
    matrix[3][4] = 1;
    matrix[3][5] = 1;
    matrix[4][3] = 1;
    matrix[4][5] = 1;
    matrix[5][1] = 1;
    matrix[5][2] = 1;
    matrix[5][3] = 1;
    matrix[5][4] = 1;

    result.push_back(1);
    backtrack(1);
    return 0;
}
