//11239 - Open Source
#include "stdio.h"
#include "string.h"
#include "vector"
#include "map"
#include "string"
#include "algorithm"

using namespace std;

struct data
{
    string srt;
    int cnt;
};

bool comp(data a,data b)
{
    if(a.cnt != b.cnt)
        return a.cnt > b.cnt;
    return a.srt < b.srt;
}

int main()
{
    arr data[110];
    map <string , int> m;
    int n,m,i,j,k,l,nodes;
    char line[510];
    freopen("1.txt","r",stdin);
    while(1)
    {
        m.clear();
        nodes = 0;
        while(scanf(" %[^\n]",line) == 1)
        {
            if(line[0] == '0')
                return 0;
            if(line[0] == '1')
                break;
            if(line[0]>= 'A' && line[0] <= 'Z')
            {
                ++nodes;
                arr[nodes-1].str = line;
                arr[nodes - 1].cnt = 0;
            }
            if(m.find(line) == m.end())
            {
                arr[nodes - 1].cnt++;
                m[line] = nodes - 1;
            }
            else
            {
                if(m[line] == nodes-1 || m[line] == -1)continue;
                else
                {
                    j = m[line];
                    arr[j].cnt--;
                    m[line] = -1;
                }
            }
        }
        sort(arr,arr+nodes,comp);
        for(i=0;i<nodes;i++)
            cout << arr[i].str << " " << arr[i].cnt << endl;
    }

    return 0;
}
