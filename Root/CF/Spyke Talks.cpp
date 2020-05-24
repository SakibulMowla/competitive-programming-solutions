#include "stdio.h"
#include "map"
#include "iostream"
using namespace std;

map <int,int> M;

int main()
{
    int i,j,k,n;
    while(cin >> n)
    {
        M.clear();
        for(i=0;i<n;i++)
        {
            cin >> j;
            if(j)
            {
                if(M.find(j) == M.end()) M[j] = 1;
                else M[j]++;
            }
        }
        k = 0;
        for(map<int,int>::iterator it = M.begin();it!=M.end();it++)
        {
            if(it->second > 2)
            {
                k = -1;
                break;
            }
            else if(it->second == 2) k++;
        }
        printf("%d\n",k);
    }

    return 0;
}
