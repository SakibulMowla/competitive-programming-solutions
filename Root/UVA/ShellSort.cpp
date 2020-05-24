            // 10152 - ShellSort
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

struct data{string name;int pos;};

vector <data> pre;
vector <string> desired;
map <string , int> m;

int main()
{
    data u;
    int test,i,n,maxim,increase;
    char arr[100];
//    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf(" %[^\n]",arr);
            u.name = arr;
            u.pos = 0;
            pre.push_back(u);
        }
        for(i=0;i<n;i++)
        {
            scanf(" %[^\n]",arr);
            m[arr] = i;
            desired.push_back(arr);
        }
        for(i=0;i<n;i++)
        {
            pre[i].pos = m[pre[i].name];
        }
        increase = -1;
        maxim = -1;
        for(i=0;i<n;i++)
        {
            if(pre[i].pos > increase)
                increase = pre[i].pos;
            else if(pre[i].pos > maxim)
                maxim = pre[i].pos;
        }
        for(i=maxim;i>=0;i--)
            cout << desired[i] << endl;
        printf("\n");
        m.clear();
        desired.clear();
        pre.clear();
    }

    return 0;
}
