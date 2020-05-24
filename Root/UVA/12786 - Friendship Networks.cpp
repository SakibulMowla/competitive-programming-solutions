#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"
#include "algorithm"
#include "queue"

using namespace std;

#define SZ 1010

int arr[SZ];

int main()
{
    int n;

    while(scanf("%d", &n) == 1)
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        int ans = 1;

        for(int i = 0; i < n; i++)
        {
            sort(arr+i, arr+n);
            reverse(arr+i, arr+n);

            for(int j = i + 1; j < n && arr[i] && arr[j]; j++)
            {
                arr[i]--;
                arr[j]--;
            }
            if(arr[i] != 0)
            {
                ans = 0;
                break;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
