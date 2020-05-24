using namespace std;

#include "stdio.h"
#include "string.h"
#include "string"
#include "sstream"
#include "vector"
#include "map"
#include "iostream"
#include "algorithm"

#define MAX 100100

struct trie
{
    int words;
    map <int , int> M;
};

vector <trie> T;
int cnt;
char word[MAX] ;

int what(char ch)
{
    if(ch >= 'a' && ch <= 'z')
        return ch-'a';
    return ch-'A'+26;
}

void addWord()
{
    int pos, node = 0, now;

    for(pos=0; ; pos++)
    {
        if(word[pos] == '\0')
        {
            T[node].words++;
            break;
        }

        now = what(word[pos]);

        if( T[node].M.find(now) == T[node].M.end() )
        {
            T.push_back(trie());
            T[node].M[now] = ++cnt;
        }

        node = T[node].M[now];
    }
}

int countWord()
{
    int pos, now, node = 0;

    for(pos=0;; pos++)
    {
        if(word[pos] == '\0')
            return T[node].words;
        now = what(word[pos]);
        if( T[node].M.find(now) == T[node].M.end() )
            return 0;
        node = T[node].M[now];
    }
}

char sen[MAX];

int main()
{
    int t=0,test,i,j,k;
    long long ans;

    scanf("%d",&test);

    while(test--)
    {
        cnt = 0;
        T.clear();
        T.push_back(trie());

        scanf("%d",&i);

        while(i--)
        {
            scanf("%s",word);
            k = strlen(word);
            if(k > 3)
                sort(word+1,word+k-1);
            addWord();
        }

        printf("Case %d:\n",++t);

        scanf("%d ",&k);
        while(k--)
        {
            ans = 1LL;
            gets(sen);
            stringstream ss(sen);

            while(ss >> word)
            {

                i = strlen(word);
                if(i > 3)
                    sort(word+1,word+i-1);
                ans = ans * (long long) countWord();

                if(ans == 0) break;
            }

            printf("%lld\n",ans);
        }
    }

    return 0;
}
