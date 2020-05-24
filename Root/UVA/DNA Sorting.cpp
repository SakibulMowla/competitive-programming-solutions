#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct data
{
    char arr[55];
    int sortedness;
};

bool comp(data a,data b)
{
    return a.sortedness < b.sortedness;
}

int main()
{
    int i,j,k,test,n,m,len,unsort,newline;
    char str[55];
    vector <data> v;
    data store;

    scanf("%d",&test);
    newline = 0;
    while(test--)
    {
        v.clear();
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%s",str);
            len = strlen(str);
            unsort = 0;

            for(j=0;j<len-1;j++)
                for(k=j+1;k<len;k++)
                    if(str[j] > str[k])
                        unsort++;
            strcpy(store.arr,str);
            store.sortedness = unsort;
            v.push_back(store);
        }

        stable_sort(v.begin(),v.end(),comp);

        vector<data>::const_iterator it;

        if(newline)
            printf("\n");
        newline = 1;

        for(it=v.begin();it!=v.end();it++)
            cout<<it->arr<<endl;
    }

    return 0;
}
