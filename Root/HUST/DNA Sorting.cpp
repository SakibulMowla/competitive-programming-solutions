#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct data {string s ; int srt ;};

bool comp(data p,data q)
{
    return p.srt < q.srt;
}

int main()
{
    data arr[1010];
    int i,j,k,n,len,cnt;
    string str;
    while(scanf("%d %d",&len,&n) == 2)
    {
        for(i=0;i<n;i++)
        {
            cin >> str;
            cnt = 0;
            for(j=0;j<len;j++)
                for(k=j+1;k<len;k++)
                    if(str[j] > str[k])
                        cnt++;
            arr[i].s = str;
            arr[i].srt = cnt;
        }
        sort(arr,arr+n,comp);
        for(i=0;i<n;i++)
            cout << arr[i].s << endl;
    }

    return 0;
}
