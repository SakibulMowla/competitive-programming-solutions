// 11283 - Playing Boggle
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

char arr[5][5] , word[20];
bool visited[5][5];

int x[] = {-1,-1,-1,0,0,1,1,1};
int y[] = {-1,0,1,-1,1,-1,0,1};
bool found;
int len;

void DFS(int u,int v,int pos)
{
    if(found)return;

    int i,a,b;
    for(i=0; i<8; i++)
    {
        a = u + x[i];
        b = v + y[i];
        if(a>=0 && b>=0 && a<4 && b<4 && !visited[a][b] && arr[a][b] == word[pos])
        {
            visited[a][b] = 1;
            if(pos == len-1)
            {
                found = true;
                return;
            }
            DFS(a,b,pos+1);
            visited[a][b] = 0;
        }
    }
}

int main()
{
    int i,j,k,n,test,t,score;
//    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    for(t=1; t<=test; t++)
    {
        for(i=0; i<4; i++)
            scanf(" %s",arr[i]);
        score = 0;
        scanf("%d",&n);
        for(k=0; k<n; k++)
        {
            scanf(" %s",word);
            found = false;
            for(i=0; i<4; i++)
                for(j=0; j<4; j++)
                    if(arr[i][j] == word[0] && !found)
                    {
                        memset(visited,0,sizeof(visited));
                        len  = strlen(word);
                        visited[i][j] = 1;
                        DFS(i,j,1);
                        if(found)
                        {
                            if(len == 3 || len == 4)
                                score += 1;
                            if(len == 5)
                                score += 2;
                            if(len == 6)
                                score += 3;
                            if(len == 7)
                                score += 5;
                            if(len >= 8)
                                score += 11;
                        }
                    }



        }
        printf("Score for Boggle game #%d: %d\n",t,score);
    }

    return 0;
}
