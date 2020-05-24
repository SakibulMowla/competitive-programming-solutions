#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int total;

bool comp(char *sym,char *num)
{
    int number;
    bool res;
    number = atoi(num) * 10;
    if( !strcmp(sym,"<") )
        res = total < number ? true : false;
    else if( !strcmp(sym,">") )
        res = total > number ? true : false;
    else if( !strcmp(sym,"<=") )
        res = total <= number ? true : false;
    else if( !strcmp(sym,">=") )
        res = total >= number ? true : false;
    else if( !strcmp(sym,"=") )
        res = total == number ? true : false;

    return res;
}

int main()
{
    int p,g,i,j,k,l,n;
    char input[10000];
    double d;
    char *pch;
    bool ans;
    map <string , int> m;

    while(scanf("%d %d",&p,&g) == 2)
    {
        for(i=0; i<p; i++)
        {
            scanf("%s %lf",input,&d);
            d *= 10;
            n = d;
            m[input] = n;
        }
        getchar();
        for(i=0; i<g; i++)
        {
            gets(input);

            pch = strtok(input," ");
            total = 0;

            while(pch != NULL)
            {
                if( isalnum(pch[0]) ) total += m[pch];
                else if( pch[0] != '+' )
                {
                    ans=comp(pch , strtok(NULL," "));
                    break;
                }
                pch = strtok(NULL," ");
            }
            if(ans==true)
                printf("Guess #%d was correct.\n",i+1);
            else
                printf("Guess #%d was incorrect.\n",i+1);
        }
    }

    return 0;
}
