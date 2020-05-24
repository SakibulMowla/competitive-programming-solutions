#include "stdio.h"
#include "string.h"
#include "string"
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

vector <string> input;
int n;

int solve()
{
    if(n == 1) return 1;
    int i,j,k,sum = 0;
    for(i=0;i<input[0].size();i++)
        if(input[0][i] != input[1][i])
            break;
    i++;
    sum += i;
    for(i=1;i<n-1;i++)
    {
        for(j=0;j<input[i].size();j++)
            if(input[i][j] != input[i+1][j])
                break;
        k = ++j;
        for(j=0;j<input[i].size();j++)
            if(input[i][j] != input[i-1][j])
                break;
        k = max(k,++j);
        sum += k;
    }
    for(i=0;i<input[n-1].size();i++)
        if(input[n-1][i] != input[n-2][i])
            break;
    i++;
    sum += i;
    return sum;
}

int main()
{
    int i,t;
    string str;
    scanf("%d",&t);
    while(t--)
    {
        input.clear();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            cin >> str;
            input.push_back(str);
        }
        sort(input.begin(),input.end());
        printf("%d\n",solve());
    }

    return 0;
}
