#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

char arr[30][30];
bool visited[30][30];

int x[] = {-1,-1,-1,0,0,1,1,1};
int y[] = {-1,0,1,-1,1,-1,0,1};
vector <string> result;
vector <char> alpha;
map <string , int> m;
int n;

void backtrack(int u,int v,int pos)
{
    int i,j,a,b;
    for(i=0; i<8; i++)
    {
        a = u + x[i];
        b = v + y[i];
        if(a>=0 && b>=0 && a<n && b<n && !visited[a][b] && alpha[pos] < arr[a][b])
        {
            visited[a][b] = 1;
            alpha.push_back(arr[a][b]);
            if(alpha.size() >= 3)
            {
                string str;
                for(j=0; j<alpha.size(); j++)
                    str += alpha[j];
                if(m.find(str) == m.end())
                {
                    result.push_back(str);
                    m[str] = 1;
                }
            }
            backtrack(a,b,pos+1);
            visited[a][b] = 0;
            alpha.pop_back();
        }
    }
}

bool comp(string a,string b)
{
    if(a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}

int main()
{
    int test,i,j;
    bool blank = false;
//    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    while(test--)
    {
        if(blank)printf("\n");
        blank = true;
        scanf("%d",&n);
        for(i=0; i<n; i++)
            scanf(" %s",arr[i]);
        result.clear();
        m.clear();
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                memset(visited,0,sizeof(visited));
                alpha.clear();
                visited[i][j] = 1;
                alpha.push_back(arr[i][j]);
                backtrack(i,j,0);
            }
        }
        sort(result.begin(),result.end(),comp);
        for(i=0; i<result.size(); i++)
            cout << result[i] << endl;
    }

    return 0;
}
