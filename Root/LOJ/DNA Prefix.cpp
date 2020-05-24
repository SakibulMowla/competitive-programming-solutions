using namespace std;

#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"

#define SZ(a) (int)a.size()
#define MAX 55

typedef long long ll;
char word[MAX];
ll ans;
char mp[26];

void init()
{
    mp['A'-'A'] = 0;
    mp['C'-'A'] = 1;
    mp['G'-'A'] = 2;
    mp['T'-'A'] = 3;
}

struct trie
{
    int prfxs, child[4];

    trie()
    {
        prfxs = 0;
        memset(child,-1,sizeof(child));
    }
};

vector <trie> T;

void addWord(int node,int pos)
{
    T[node].prfxs++;
    ans = max(ans , (ll)pos * (ll)T[node].prfxs);

    if(word[pos] == '\0')
        return;

    int now = mp[word[pos]-'A'];

    if(T[node].child[now] == -1)
    {
        T[node].child[now] = SZ(T);
        T.push_back(trie());
    }

    int nextnode = T[node].child[now];

    addWord(nextnode , pos+1);
}

int main()
{
    init();
    int t=0,test,n;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%d",&n);

        ans = 0LL;
        T.clear();
        T.push_back(trie());

        while(n--)
        {
            scanf("%s",word);
            addWord(0,0);
        }

        printf("Case %d: %lld\n",++t,ans);
    }

    return 0;
}
