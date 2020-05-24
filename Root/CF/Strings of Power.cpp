#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;
#define SZ 1000010

char txt[SZ+5] , pat[SZ+5];
int lps[SZ+5];

vector <int> H,M;

void pre_process()
{
    int j,len,M;
    M = strlen(pat);
    len = 0;
    lps[0] = 0;

    for(j=1;j<M;j++)
    {
        while(len > 0 && pat[len] != pat[j])
            len = lps[len-1];
        if(pat[len] == pat[j])
            len++;
        lps[j] = len;
    }
    return;
}

void KMP_search()
{
    pre_process();

    int i,j,n,m,cnt;
    n = strlen(txt);
    m = strlen(pat);
    cnt = 0;
    i = 0; //index of txt
    j = 0; //index of pat
    for(i=0;i<n;i++)
    {
        while(j > 0 && txt[i] != pat[j])
            j = lps[j-1];
        if(pat[j] == txt[i])
            j++;
        if(j == m)
        {
            cnt++;
            j = lps[j-1];
            H.push_back(i);
        }
    }

//    return cnt;
}

void KMP_search1()
{
    pre_process();

    int i,j,n,m,cnt;
    n = strlen(txt);
    m = strlen(pat);
    cnt = 0;
    i = 0; //index of txt
    j = 0; //index of pat
    for(i=0;i<n;i++)
    {
        while(j > 0 && txt[i] != pat[j])
            j = lps[j-1];
        if(pat[j] == txt[i])
            j++;
        if(j == m)
        {
            cnt++;
            j = lps[j-1];
            M.push_back(i);
        }
    }
}

int main()
{
    int t,test,i,j,k,p,q;
    long long ans;
    t = 0;
    while(scanf("%s",&txt) == 1)
    {
        H.clear();
        M.clear();
        strcpy(pat,"heavy");
        KMP_search();
        strcpy(pat,"metal");
        KMP_search1();

        ans = 0;

        p = H.size();
        q = M.size();

        j = 0;

        for(i=0;i<p;i++)
        {
//            if(q)
            while( j < q && M[j] < H[i]) j++;

            ans += (long long ) q - (long long ) j;
        }

        cout << ans << "\n";
    }

    return 0;
}
