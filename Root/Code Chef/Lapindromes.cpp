using namespace std;

#include "stdio.h"
#include "string.h"
#include "string"
#include "iostream"
#include "algorithm"

int main()
{
    int i,j,k,t;
    string s, a, b;

    scanf("%d",&t);
    while(t--)
    {
        cin >> s;
        k = s.size();
        j = k/2;
        a =s.substr(0,j);
        j += k % 2;
        b = s.substr(j);

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if(a == b) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
