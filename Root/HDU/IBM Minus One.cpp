#include "stdio.h"
#include "string"
#include "iostream"

using namespace std;

int main()
{
    int t, test=0;
    string a;

    scanf("%d",&t);

    while(t--)
    {
        cin >> a;
        for(int i=0; i<a.size(); i++)
        {
            if(a[i] == 'Z') a[i] = 'A';
            else a[i] = (char)(a[i] + 1);
        }
        printf("String #%d\n",++test);
        cout << a << "\n\n";
    }

    return 0;
}

