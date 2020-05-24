#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
//    freopen("1.txt","r",stdin);
    int arr[1010] , n , m , i , j , num , t = 1 , ans ,sum ,flag;
    while(scanf("%d",&n) == 1 && n)
    {
        for(i=0;i<n;i++) scanf("%d",&arr[i]);
        sort(arr,arr+n);
        scanf("%d",&m);
        printf("Case %d:\n",t++);
        while(m--)
        {
            scanf("%d",&num);
            ans = 1<<28;
            flag = 0;
            for(i=0;i<n;i++)
            {
                for(j=i+1;j<n;j++)
                {
                    sum = arr[i] + arr[j];
                    if(abs(sum-num) < abs(ans-num))
                        ans = sum;
                    if(sum>num)break;
                    if(sum == num)
                    {
                        flag == 1;
                        break;
                    }
                }
                if(flag == 1) break;
            }
            printf("Closest sum to %d is %d.\n",num,ans);
        }
    }

    return 0;
}
