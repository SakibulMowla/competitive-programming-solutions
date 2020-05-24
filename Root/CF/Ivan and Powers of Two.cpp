#include <cstdio>
#include <string>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;


int main()
{
    char str[100],str1[100],str2[100];
    int d;

    while(scanf(" %[^\n]",str) == 1)
    {
        sscanf(str,"%s %s %d",str1,str2,&d);
        printf("%s %s %d\n",str1,str2,d);
    }


}
