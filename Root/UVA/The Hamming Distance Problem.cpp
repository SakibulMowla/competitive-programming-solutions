#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char arr[20];
int H,N,ones;

int main()
{
    int i,test;
    bool blank = false;
//    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    while(test--)
    {
        if(blank)
            printf("\n");
        blank = true;
        scanf("%d %d",&N,&H);
        for(i=0;i<N-H;i++)
            arr[i] = '0';
        for(;i<N;i++)
            arr[i] = '1';
        arr[i] = '\0';
        do
        printf("%s\n",arr);
        while(next_permutation(arr,arr+N));
    }

    return 0;
}
