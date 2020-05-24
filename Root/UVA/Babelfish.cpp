#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <iostream>

using namespace std;

int main()
{
    int i,j,k,l;
    char input[200],a[100],b[100];
    string p,q;
    map <string,string> M;
    while(gets(input))
    {
        if(strcmp(input,"\0") == 0)break;
        sscanf(input,"%s %s",a,b);
        p=a;
        q=b;
        M[q] = p;
    }

    while(scanf("%s",input) == 1)
    {
        if(M.find(input)!=M.end())
            cout << M[input] << endl;
        else
            printf("eh\n");
    }

    return 0;
}
