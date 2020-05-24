#include "stdio.h"
#include "string.h"
#include "string"
#include "map"
#include "iostream"

using namespace std;

#define Y second

int main()
{
    int i,k,l,t;
    string str;
    map <char , int> mci;
    map <char , int> :: iterator it;
    scanf("%d",&t);
    while(t--)
    {
        cin >> str;
        l = str.size();
        mci.clear();
        for(i=0; i<l; i++)
        {
            if( tolower(str[i]) >= 'a' && tolower(str[i]) <= 'z')
                mci[ str[i] ]++;
        }
        k = 0;
        for(it=mci.begin(); it!=mci.end(); it++)
        {
            i = it->Y;
            k += i / 2;
            k += i% 2;
        }
        printf("%d\n",k);
    }

    return 0;
}
