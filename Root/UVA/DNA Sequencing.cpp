using namespace std;

#include "stdio.h"
#include "string.h"
#include "vector"
#include "set"
#include "iostream"

#define MAX 310

struct trie
{
    int prfxs , child[4];
    trie()
    {
        prfxs = 0;
        child[0] = child[1] = child[2] = child[3] = -1;
    }
};

vector <trie> T;
set <string> unique;
set <string>::iterator it;
char mic[] = {'a' , 'c' , 'g' , 't'} , *word;
int mci[150] , nodes, reslen;

void add_1st_word()
{
    int node, pos, now;
    node = 0;

    for(pos=0;; pos++)
    {
        if(word[pos] == '\0') break;

        T[node].prfxs = 1;
        now = mci[ word[pos] ];

        if(T[node].child[now] == -1)
        {
            T[node].child[now] = ++nodes;
            T.push_back(trie());
        }

        node = T[node].child[now];
    }

    return;
}

void add_2nd_word()
{
    int node , pos , now;
    node = 0;

    for(pos=0;; pos++)
    {
        if(word[pos] == '\0') break;

        now = mci[ word[pos] ];

        if(T[node].child[now] == -1) break;

        node = T[node].child[now];
    }

    if(pos > reslen)
    {
        reslen = pos;
        T[node].prfxs = 2;
    }
    else if(pos == reslen)
    {
        T[node].prfxs = 2;
    }

    return;
}

char tmp[MAX];

void search_trie(int node,int pos)
{
    tmp[pos] = '\0';

    if(pos == reslen && T[node].prfxs == 2)
        unique.insert(tmp);

    for(int i=0; i<4; i++)
        if(T[node].child[i] != -1)
            tmp[pos] = mic[i] , search_trie(T[node].child[i] , pos+1);

    return;
}

int main()
{
    mci['a'] = 0;
    mci['c'] = 1;
    mci['g'] = 2;
    mci['t'] = 3;

    int i,k;
    char arr[MAX];
    bool blank = false;

    while( gets(arr) )
    {
        if(blank) printf("\n");
        else blank = true;

        T.clear();
        T.push_back(trie());
        unique.clear();
        nodes = 0;

        k = strlen(arr);
        for(i=0; i<k; i++)
            word = arr + i , add_1st_word();

        gets(arr);
        k = strlen(arr);
        reslen = 0;

        for(i=0; i<k; i++)
            word = arr + i , add_2nd_word();

        if(reslen == 0)
        {
            printf("No common sequence.\n");
        }
        else
        {
            search_trie(0 , 0);

            for(it=unique.begin(); it!=unique.end(); it++)
                printf("%s\n",(*it).c_str());
        }

        gets(arr);
    }

    return 0;
}
