#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int arr[55][55];

int main()
{
    int n,m,i,j,k,l,a[55],best,swaps,lowest,pos;
    vector <int> v[55];
    while(scanf("%d",&n) == 1)
    {
        swaps = 0;
        for(i=1;i<55;i++)
            for(j=1;j<55;j++)
                arr[i][j] = -1;
        best = 0;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]),best = a[i] > best ? a[i] : best;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=a[i];j++)
                scanf("%d",&arr[i][j]);
        }
        lowest = 10000;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=a[i]-1;j++)
            {
                for(k=j+1;k<=a[i];k++)
                {
                    if(arr[i][k] < lowest)
                    {
                        lowest = arr[i][k];
                        pos = k;
                    }
                }
                if(arr[i][j] > lowest)
                {

                    swap(arr[i][j] , arr[i][pos]);
                    v[swaps].push_back(i);
                    v[swaps].push_back(j);
                    v[swaps].push_back(i);
                    v[swaps].push_back(pos);
                    swaps++;
                    printf("y\n");
                }
            }
        }
        lowest = 10000;
        for(j=1;j<=best;j++)
        {
            for(i=1;i<=n-1;i++)
            {
                for(k=i+1;k<=n;k++)
                {
                    if(arr[j][k] < lowest && arr[j][k] != -1)
                    {
                        lowest = arr[j][k];
                        pos = k;
                    }
                }
                if(arr[j][i] > lowest)
                {

                    swap(arr[j][i] , arr[j][pos]);
                    v[swaps].push_back(j);
                    v[swaps].push_back(i);
                    v[swaps].push_back(j);
                    v[swaps].push_back(pos);
                    swaps++;
                }
            }
        }
        printf("%d\n",swaps);
        for(i=0;i<swaps;i++)
        {
            printf("%d",v[i][0]);
            for(j=1;j<4;j++)
                printf(" %d",v[i][j]);
            printf("\n");
        }
        for(i=0;i<55;i++)
            v[i].clear();
    }

    return 0;
}
