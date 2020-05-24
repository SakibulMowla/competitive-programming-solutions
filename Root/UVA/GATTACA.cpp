using namespace std;

#include "stdio.h"
#include "string.h"
#include "string"
#include "iostream"

#define MAX 1010
#define MAX1 1000100

struct trie
{
    int prfxs , child[4];
    trie()
    {
        prfxs = 0;
        memset(child,-1,sizeof(child));
    }
}T[MAX1];


int M[200];
char mis[] = {'A' , 'C' , 'G' , 'T'};
char arr[MAX] , *word , tmp[MAX];
int cnt , reslen , rescnt;

void addWord()
{
    int node, pos, now;
    node = pos = 0;

    for(pos=0;; pos++)
    {
        T[node].prfxs++;

        if(word[pos] == '\0')
            return;

        now = M[ word[pos] ];

        if(T[node].child[now] == -1)
            T[node].child[now] = ++cnt;

        node = T[node].child[now];
    }
}

void search(int node,int pos)
{
    tmp[pos] = '\0';

    if(pos > reslen && T[node].prfxs > 1)
    {
        reslen = pos;
        rescnt = T[node].prfxs;
        strcpy(arr , tmp);
    }

    int i;

    for(i=0; i<4; i++)
        if(T[node].child[i] != -1)
            tmp[pos] = mis[i] , search(T[node].child[i] , pos+1);

}


int main()
{
    M['A'] = 0;
    M['C'] = 1;
    M['G'] = 2;
    M['T'] = 3;

    int t,i,k;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%s",arr);

        k = strlen(arr);
        reslen = rescnt = cnt = 0;

        for(i=0; i<k; i++)
            word = arr + i , addWord();

        search(0 ,0);

        if(reslen > 0) printf("%s %d\n",arr , rescnt);
        else printf("No repetitions found!\n");

        for(i=0; i<=cnt; i++)
            T[i] = trie();
    }

    return 0;
}
