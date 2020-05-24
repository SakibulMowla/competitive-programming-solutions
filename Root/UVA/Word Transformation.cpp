#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <queue>
#include <map>
#include <iostream>

#define inf 999999999

using namespace std;

map<string,int>M;
int nodes;
int mat[205][205];
char arr[205][20];

int adj_match(char a[20],char b[20])
{
    int len1,len2,i,k;
    len1=strlen(a);
    len2=strlen(b);
    if(len1!=len2)return -1;
    k=0;
    for(i=0;i<len1;i++)
    {
        if(a[i] != b[i])
            k++;
    }
    return k;
}

void floyd_warshall(void)
{
    int i,j,k;
    for(k=1;k<=nodes;k++)
        for(i=1;i<=nodes;i++)
            for(j=1;j<=nodes;j++)
                mat[i][j] = min(mat[i][j] , mat[i][k] + mat[k][j]);
    return;
}

int main()
{
    int i,j,test,ans,p,q,k;
    char dic[40],word1[20],word2[20];
    scanf("%d",&test);
    k=0;
    while(test--)
    {
        M.clear();
        nodes=0;
        i=0;
        while(scanf("%s",dic)==1)
        {
            if(strcmp(dic,"*") == 0)break;
            M[dic]=++nodes;
            strcpy(arr[++i],dic);
        }
        getchar();
        for(i=1;i<=nodes;i++)
            for(j=1;j<=nodes;j++)
                mat[i][j] = mat[j][i] = inf;

        for(i=1;i<nodes;i++)
        {
            for(j=i+1;j<=nodes;j++)
            {
                ans=adj_match(arr[i],arr[j]);
                if(ans == 1)
                {
                    p=M[arr[i]];
                    q=M[arr[j]];
                    mat[p][q] = mat[q][p] = 1;
                }
            }
        }

        floyd_warshall();
        if(k)printf("\n");
        k=1;
        while(gets(dic))
        {
            if(strcmp(dic,"\0") == 0)break;
            sscanf(dic,"%s %s",word1,word2);
            p=M[word1];
            q=M[word2];
            printf("%s %s %d\n",word1,word2,mat[p][q]);
        }
    }

    return 0;
}
