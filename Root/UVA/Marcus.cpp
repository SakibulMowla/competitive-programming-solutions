#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"

using namespace std;
char ans[4][10] = {"forth","right","left"};
char arr[10][10];
int avail[300] , corr[300];
int r , c;
vector <int> v;
int x[] = {-1,0,0};
int y[] = {0,1,-1};
void backtrack(int n,int m)
{
    int i,p,q;
    if(v.size() == 7)
    {
        printf("%s",ans[v[0]]);
        for(i=1;i<7;i++)
            printf(" %s",ans[v[i]]);
        printf("\n");
        return;
    }

    for(i=0;i<3;i++)
    {
        p = x[i] + n;
        q = y[i] + m;
        if(p>=0 && q>=0 && p<r && q<c && corr[arr[p][q]] && avail[arr[p][q]] )
        {
            v.push_back(i);
            avail[arr[p][q]] = 0;

            backtrack(p,q);

            avail[arr[p][q]] = 1;
            v.pop_back();
        }
    }
}

int main()
{
    corr['I'] = corr['E'] = corr['H'] = corr['O'] = corr['V'] = corr['A'] = corr['#']= 1;
    int i,j,t,test,s1,s2;
//    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    while(test--)
    {
        memset(avail,1,sizeof(avail));
        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                scanf(" %c",&arr[i][j]);
                if(arr[i][j] == '@')
                    s1=i,s2=j;
            }
        backtrack(s1,s2);
    }

    return 0;
}
