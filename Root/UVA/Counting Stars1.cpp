#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int r,c,i,j,count;
    char arr[110][110],z;
    while(scanf("%d %d%c",&r,&c,&z)==3)
    {
        if(r==0 && c==0)
            break;
        memset(arr,46,sizeof(arr));
        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
                cin>>arr[i][j];

        count=0;
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                if(arr[i][j]=='*')
                {
                    if(arr[i-1][j-1]=='*') continue;

                    if(arr[i-1][j]=='*') continue;

                    if(arr[i-1][j+1]=='*') continue;

                    if(arr[i][j-1]=='*') continue;

                    if(arr[i][j+1]=='*') continue;

                    if(arr[i+1][j-1]=='*') continue;

                    if(arr[i+1][j]=='*') continue;

                    if(arr[i+1][j+1]=='*') continue;

                    count++;
                }
            }
        }
        printf("%d\n",count);
    }

    return 0;
}
