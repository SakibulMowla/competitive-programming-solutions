#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,i,k,arr[1422+10];
    while(cin >> n && n)
    {
        k=0;
        for(i=0;i<n;i++)
            cin >> arr[i];
        sort(arr,arr+n);
        for(i=1;i<n;i++)
        {
            if(arr[i]-arr[i-1]>200)
                k=1;
        }
        if(2*(1422-arr[n-1])>200) k=1;
        if(k==0)
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
