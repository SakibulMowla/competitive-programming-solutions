//Waking up brain
#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "iostream"

using namespace std;

const int SZ = 26;
int n;
bool matrix[SZ][SZ];
bool awake[SZ] , new_awake[SZ];

void take_input()
{
    memset(awake,false,sizeof(awake));
    memset(matrix,false,sizeof(matrix));
    int m,i;
    char arr[30];
    scanf("%d",&m);
    scanf(" %s",arr);
    for(i=0; arr[i]; i++)
        awake[arr[i]-'A'] = true;
    for(i=0; i<m; i++)
    {
        scanf(" %s",arr);
        matrix[arr[0]-'A'][arr[1]-'A'] = true;
        matrix[arr[1]-'A'][arr[0]-'A'] = true;
    }
}

int result()
{
    int i,j,k,cnt;
    for(k=0; k<SZ; k++)
    {
        if(count(awake, awake+SZ, true) == n)
            return k;
        memset(new_awake,false,sizeof(new_awake));
        for(i=0; i<SZ; i++)
        {
            cnt = 0;

            for(j=0; j<SZ; j++)
                if(awake[j] && matrix[i][j])
                    cnt++;

            if(cnt >= 3)
                new_awake[i] = true;
        }

        for(i=0; i<SZ; i++)
            if(new_awake[i])
                awake[i] = true;
    }
    return -1;
}

int main()
{
    int ans;
//    freopen("1.txt","r",stdin);
    while(scanf("%d",&n) == 1)
    {
        take_input();
        ans = result();
        if(ans == -1)
            printf("THIS BRAIN NEVER WAKES UP\n");
        else
            printf("WAKE UP IN, %d, YEARS\n",ans);
    }

    return 0;
}
