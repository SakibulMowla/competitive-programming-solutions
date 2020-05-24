#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define max 110

char arr[max][max];
int count;
int row;
int col;
bool travel[max][max];

int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

void dfs(int n,int m)
{
    int i;
    if(n<0 || m<0 || n>=row || m>=col || arr[n][m]=='L' || travel[n][m]==1) return;
    travel[n][m]=1;
    count++;
    for(i=0;i<8;i++)
        dfs( n+dx[i],m+dy[i]);
    return;
}

int main(int argc, char** argv)
{
    int i,k,p,q;

    scanf("%d\n\n",&k);
    for(i=0;i<k;i++)
    {

        row=0;col=0;

        if(i!=0)printf("\n");
        char line[max];
        while(gets(line) && strlen(line) > 0)
        {
            if(line[0]=='L'  || line[0]=='W')
            {
                strcpy(arr[row],line);
                col=strlen(line);
                row++;
            }
            else
            {
                sscanf(line,"%d %d",&p,&q);
                memset(travel,0,sizeof(travel));
                count=0;
                dfs(p-1,q-1);
                printf("%d\n",count);
            }
        }

    }
    return 0;
}
