#include "stdio.h"
#include "string.h"
#include "string"
#include "iostream"
#include "map"

using namespace std;

map <string , int> M;

int main()
{
    string s;
    int n,i,j,k;
    scanf("%d",&n);
    while(n--)
    {
        cin >> s;
        if(M.find(s) == M.end())
        {
            printf("OK\n");
            M[s] = 1;
        }
        else
        {
            cout << s << M[s] << endl;
            M[s]++;
        }
    }

    return 0;
}
