#include <cstdio>
#include <cctype>
#include <iostream>

using namespace std;

int main()
{
    int i,n;
    char prech=' ',ch,tau;
    i=n=0;
    while(scanf("%c",&ch)!=EOF)
    {
        if(ch=='*') break;
        if(i==0 && prech==' ')
            tau=tolower(ch);
        if(prech==' ' && tolower(ch)!=tau)
            n=1;
        i++;
        prech=ch;
        if(ch=='\n')
        {
            if(n==0)
                cout<<"Y"<<endl;
            else
                cout<<"N"<<endl;
            i=n=0;
            prech=' ';
        }
    }

    return 0;
}
