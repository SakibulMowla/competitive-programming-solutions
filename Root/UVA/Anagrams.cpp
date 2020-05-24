using namespace std;

#include "stdio.h"
#include "string.h"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "iostream"

#define MP(a, b) make_pair(a, b)
#define sz(a) (int)a.size()
typedef pair<string, string> pss;

set <pss> myset;
set <pss>:: iterator it ;

struct data
{
    string s1, s2;
};

data arr[110];

int main()
{
    int t, i, j, k, n;
    string s;

    scanf("%d",&t);
    getchar();
    getchar();

    while(t--)
    {
        myset.clear();
        n = 0;

        while(getline(cin,s))
        {
            if(s == "") break;
            arr[n].s1 = s;
            arr[n].s2 = "";
            k = sz(s);
            for(i=0; i<k; i++)
            {
                if(s[i] == ' ') continue;
                arr[n].s2 += s[i];
            }
            sort(arr[n].s2.begin(), arr[n].s2.end());
            n++;
        }

        for(i=0; i<n; i++)
            for(j=i+1; j<n; j++)
                if(arr[i].s2 == arr[j].s2)
                    myset.insert(MP( min( arr[i].s1 , arr[j].s1 ) , max( arr[i].s1 , arr[j].s1 ) ));

        for(it=myset.begin(); it!=myset.end(); it++)
            printf("%s = %s\n",it->first.c_str(), it->second.c_str());

        if(t) printf("\n");
    }

    return 0;
}
