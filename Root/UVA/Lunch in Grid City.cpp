#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    vector <int> street , avenue;
    int test,i,j,k,f;
//    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d %d",&i,&j,&f);
        for(i=0;i<f;i++)
        {
            scanf("%d %d",&j,&k);
            street.push_back(j);
            avenue.push_back(k);
        }
        sort(street.begin(),street.end());
        sort(avenue.begin(),avenue.end());
        if(f&1) j = (f+1) / 2;
        else j = f/2;
        printf("(Street: %d, Avenue: %d)\n",street[j-1],avenue[j-1]);
        street.clear();
        avenue.clear();
    }

    return 0;
}
