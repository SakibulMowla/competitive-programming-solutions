#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

int arr[20];
int n,total,flag;
vector <int> result;

void backtrack(int sum,int pos)
{
    int i;
    if(sum == total)
    {
        flag = 1;
        cout<<result[0];
        for(i=1; i<result.size(); i++)
            cout<<"+"<<result[i];
        printf("\n");
        return;
    }
    if(sum > total)
        return;
    for(i=pos; i<=n;)
    {
        result.push_back(arr[i]);
        backtrack(sum+arr[i],i+1);
        i++;
        while(arr[i-1] == arr[i])
            i++;
        result.pop_back();
    }
}

int main()
{
    int i;
    while(scanf("%d %d",&total,&n) == 2)
    {
        if(n == 0)break;
        for(i=1; i<=n; i++)
            scanf("%d",&arr[i]);
        printf("Sums of %d:\n",total);
        flag = 0;
        backtrack(0,1);
        if(flag == 0)
            printf("NONE\n");
    }

    return 0;
}
