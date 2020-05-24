#include "stdio.h"
#include "string"
#include "iostream"
using namespace std;
string s;

int main()
{
    int i,k,l;
    while(cin>>s)
    {
        k = 0;
        l = s.size();
        for(i=0;i<l;i++)
        {
            if(s[i] == '0')
            {
                k=1;
                s.erase(i,1);
                break;
            }
        }
        if(k == 0) s.erase(0,1);
        printf("%s\n",s.c_str());
    }

    return 0;
}
