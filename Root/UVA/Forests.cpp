#include "stdio.h"
#include "string.h"
#include "set"
#include "iostream"
#include "algorithm"

using namespace std;

#define SZ 110

set <int> myset[SZ];

int main()
{
//    freopen("1.txt","r",stdin);
    int test, p, t, i, j, k, cnt;
    char arr[100];

    scanf("%d",&test);

    while(test--)
    {
        scanf("%d %d",&p,&t);

        getchar();

        for(i=0; i<=p; i++)
            myset[i].clear();

        while(gets(arr) && strlen(arr))
        {
            sscanf(arr,"%d %d",&j,&k);
            myset[j].insert(k);
        }

        sort(myset+1, myset+p+1);

        cnt = 1;

        for(i=2; i<=p; i++)
            if(myset[i] != myset[i-1])
                cnt++;

        printf("%d\n",cnt);

        if(test) printf("\n");
    }


    return 0;
}












