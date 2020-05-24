#include "stdio.h"
#include "string.h"
#include "string"
#include "map"
#include "iostream"

using namespace std;

map <string , int> msi;

void init()
{
    msi["zero"] = 0;
    msi["one"] = 1;
    msi["two"] = 2;
    msi["three"] = 3;
    msi["four"] = 4;
    msi["five"] = 5;
    msi["six"] = 6;
    msi["seven"] = 7;
    msi["eight"] = 8;
    msi["nine"] = 9;
    msi["ten"] = 10;

    msi["eleven"] = 11;
    msi["twelve"] = 12;
    msi["thirteen"] = 13;
    msi["fourteen"] = 14;
    msi["fifteen"] = 15;
    msi["sixteen"] = 16;
    msi["seventeen"] = 17;
    msi["eighteen"] = 18;
    msi["nineteen"] = 19;

    msi["twenty"] = 20;
    msi["thirty"] = 30;
    msi["forty"] = 40;
    msi["fifty"] = 50;
    msi["sixty"] = 60;
    msi["seventy"] = 70;
    msi["eighty"] = 80;
    msi["ninety"] = 90;
}

int main()
{
    init();
    freopen("1.txt","r",stdin);
    int neg,cur,hun,mil,thou,i,j,k;
    char arr[5000] , *str;
    while(scanf(" %[^\n]",arr) == 1)
    {
        cur = hun = mil = thou = neg = 0;
        str = strtok(arr," ");
        while(str)
        {
            if(strcmp(str,"negative") == 0)
                neg = 1;
            else if(strcmp(str,"hundred") == 0)
                hun += cur , cur = 0;
            else if(strcmp(str,"thousand") == 0)
                thou += cur + (hun * 100) , cur = 0 , hun = 0;
            else if(strcmp(str,"million") == 0)
                mil += cur + (hun*100) + (thou * 1000), cur = 0 , hun = 0 , thou = 0;
            else
                cur += msi[str];
            str = strtok(NULL," ");
        }
        if(neg) printf("-");
        printf("%d\n",(mil*1000000)+(thou*1000)+(hun*100)+cur);
    }

    return 0;
}
