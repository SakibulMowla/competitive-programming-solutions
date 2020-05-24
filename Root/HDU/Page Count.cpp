#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "set"
#include "iostream"

using namespace std;

#define SZ 1010

char arr[SZ], arr1[SZ];
char *str, *str1, *str2;


set <int> myset;


int main()
{
    int i, j, k, n, m;
    bool found;


    while(scanf("%d",&n) == 1 && n)
    {
        scanf("%s",arr);

        myset.clear();

        str = strtok(arr,",");

        while(str != NULL)
        {
            found = false;

            for(i=0;str[i];i++)
                if(str[i] == '-')
                    found = true;

            if(found)
            {
                sscanf(str,"%d-%d",&i,&j);
                for(k=i; k<=j&&k<=n; k++)
                    myset.insert(k);
            }
            else
            {
                sscanf(str,"%d",&i);
                if(i <= n)
                    myset.insert(i);
            }

            str = strtok(NULL, ",");
        }

        printf("%d\n",myset.size());
    }


    return 0;
}










