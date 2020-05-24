#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

int arr[25];
int n,tracks,maxim;
vector <int> result , best;

void backtrack(int pos,int sum)
{
    int i;
    if(sum <=n && sum > maxim)
    {
        best.clear();
        maxim = sum;
        for(i=0;i<result.size();i++)
            best.push_back(result[i]);
        return;
    }
    if(sum > n)
        return;
    for(i=pos;i<tracks;i++)
    {
        result.push_back(arr[i]);
        backtrack(i+1,sum+arr[i]);
        result.pop_back();
    }
}

int main()
{
    int i;
    while(scanf("%d",&n) == 1)
    {
        scanf("%d",&tracks);
        for(i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        maxim = 0;
        backtrack(1,0);
    }

    return 0;
}
