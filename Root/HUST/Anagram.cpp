#include "stdio.h"
#include "string"
#include "algorithm"
#include "iostream"

using namespace std;

bool comp(const char &a,const char &b)
{
    int c = tolower(a) - tolower(b);
    return c ? c < 0 : a < b;
}

int main()
{
    int test;
    string str;
    scanf("%d",&test);
    while(test--)
    {
        cin >> str;
        sort(str.begin(),str.end(),comp);
        do
            cout << str << endl;
        while(next_permutation(str.begin(),str.end(),comp));
    }

    return 0;
}
