using namespace std;

#include "stdio.h"
#include "string.h"
#include "string"
#include "queue"
#include "map"
#include "vector"
#include "iostream"
#include "algorithm"

#define MAX 25150

int par[MAX];
vector <string> dict[20];
vector <string> subdict;
queue <int> Q;
vector <int> adj[MAX];
map <string , int> M;
map <int , string> mis;

bool check(string a,string b)
{
    int i, j=0, k=a.size();
    for(i=0;i<k;i++)
        if(a[i] ^ b[i])
            j++;
    return j == 1;
}

bool bfs(int as,int bs)
{
    int u,v,j,k;

    memset(par,0,sizeof(par));
    while(!Q.empty()) Q.pop();

    par[as] = as;
    Q.push(as);

    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();

        if(u == bs) break;
        k = adj[u].size();

        for(v=0;v<k;v++)
        {
            j = adj[u][v];
            if(!par[j])
            {
                par[j] = u;
                Q.push(j);
            }
        }
    }

    if(par[bs]) return true;
    return false;
}

void printpath(int as,int bs)
{
    if(as != bs)
        printpath(as , par[bs]);
    printf("%s\n",mis[bs].c_str());
}

int main()
{
    string word , a , b;
    bool blank = false;
    int as,bs,i,k,p,q,node;

    node = 0;

    while(getline(cin,word) && word.size())
    {
        if(dict[ word.size() ].empty()) dict[ word.size() ].push_back("");
        dict[ word.size() ].push_back(word);
        if(M.find(word) == M.end())
            M[word] = ++node , mis[node] = word;
    }

    for(i=1;i<=16;i++)
    {
        k = dict[i].size();
        for(p=0;p<k;p++)
            for(q=p+1;q<k;q++)
                if(check(dict[i][p] , dict[i][q]))
                    adj[ M[ dict[i][p] ] ].push_back( M[ dict[i][q] ] ),
                    adj[ M[ dict[i][q] ] ].push_back( M[ dict[i][p] ] );
    }

    while(cin >> a >> b)
    {
        if(blank) printf("\n");
        else blank = true;

        if(a.size() != b.size() || M.find(a) == M.end() || M.find(b) == M.end() || !bfs(M[a] , M[b]))
            printf("No solution.\n");

        else
            printpath(M[a] , M[b]);
    }

    return 0;
}
