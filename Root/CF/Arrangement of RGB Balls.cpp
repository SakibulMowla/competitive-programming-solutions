#include "bits/stdc++.h"
using namespace std;

int arr[4];

int main()
{
    int t;

    scanf("%d",&t);


    while(t--)
    {
        scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);

        sort(arr,arr+3);

        if(arr[0] < 0)
            printf("0\n");

        else if(arr[2]-arr[0] > 1)
            printf("0\n");

        else if(arr[2] == arr[1] && arr[1] == arr[0])
            printf("6\n");

        else if(arr[0] == 0 && arr[1] == 0)
            printf("1\n");

        else if(arr[2] == arr[1])
            printf("2\n");

        else if(arr[1] == arr[0])
            printf("2\n");

    }

    return 0;
}
