#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t,test,n,k,i;
    t = 0;
    char arr[100];
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
            arr[i] = 'A'+i;
        arr[i] = '\0';
        i = 0;
        printf("Case %d:\n",++t);
        do
        {
            i++;
            printf("%s\n",arr);
        }while(next_permutation(arr,arr+n) && i<k);
    }

    return 0;
}
