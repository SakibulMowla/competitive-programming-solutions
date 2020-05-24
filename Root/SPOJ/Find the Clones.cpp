using namespace std;

#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"

#define MAX 20010

struct trie
{
    int words,child[4];
    trie()
    {
        words = 0;
        child[0] = child[1] = child[2] = child[3] = -1;
    }
};

vector <trie> T;
char arr[22];
int n,m,cnt;
int M[150] , ans[MAX];

void addWord()
{
    int pos, node, now;

    node = 0;

    for(pos=0;;pos++)
    {
        if(arr[pos] == '\0')
        {
            T[node].words++;
            break;
        }
        now = M[ arr[pos] ];
        if(T[node].child[now] == -1)
        {
            T[node].child[now] = ++cnt;
            T.push_back(trie());
        }
        node = T[node].child[now];
    }

    return;
}

void search_trie(int node,int pos)
{
    if(pos == m)
    {
        ans[ T[node].words ]++;
        return;
    }
    int i;
    for(i=0;i<4;i++)
        if(T[node].child[i] != -1)
            search_trie(T[node].child[i] , pos+1);
}

int main()
{
//    freopen("1.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    M['A']= 0;
    M['C']= 1;
    M['G']= 2;
    M['T']= 3;

    int i;

    while(scanf("%d %d",&n,&m) == 2 && (n || m))
    {
        T.clear();
        T.push_back(trie());
        memset(ans , 0 , sizeof(int)*(n+2));
        cnt = 0;

        for(i=0;i<n;i++)
            scanf("%s",arr) , addWord();

        search_trie(0 , 0);

        for(i=1;i<=n;i++)
            printf("%d\n",ans[i]);
    }

    return 0;
}
