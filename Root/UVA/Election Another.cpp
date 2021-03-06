#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

struct data
{
    char arr[100];
    int vote;
};

bool comp(data a,data b)
{
    return a.vote > b.vote;
}

int main()
{
    int t,test,i,n,m,tie,size;
    char can[100],party[100];
    data u;
    map <string , string> mstr;
    map <string , int> mint;
    vector <data> v;
    scanf("%d",&test);
    for(t=0; t<test; t++)
    {
        tie = 0;
        v.clear();
        mstr.clear();
        mint.clear();
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf(" %[^\n]",can);
            scanf(" %[^\n]",party);
            mstr[can] = party;
            mint[can] = 0;
            strcpy(u.arr,can);
            u.vote = 0;
            v.push_back(u);
        }
        scanf("%d",&m);
        for(i=0; i<m; i++)
        {
            scanf(" %[^\n]",can);
            if(mstr.find(can) == mstr.end())
                continue;
            mint[can] += 1;
        }

        size = v.size();

        for(i=0;i<size;i++)
        {
            v[i].vote = mint[v[i].arr];
        }

        sort(v.begin(),v.end(),comp);

        if(v.size() > 1)
        {
            if(v[0].vote == v[1].vote)
            {
                tie = 1;
            }
        }
        if(tie == 1)
            printf("tie\n");
        else
            cout<<mstr[v[0].arr]<<endl;
        if(t<test-1)
            printf("\n");
    }

    return  0;
}
