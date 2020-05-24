#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int i,a,b;
    /*vector <int> ans[10];
    for(i=0;i<99;i++)
    {
        a = i/10;
        b = i%10;
        if((a+b)*(a+b) == i)
        ans[2].push_back(i);
    }
    for(i=0;i<9999;i++)
    {
        a = i/100;
        b = i%100;
        if((a+b)*(a+b) == i)
        ans[4].push_back(i);
    }
    for(i=0;i<999999;i++)
    {
        a = i/1000;
        b = i%1000;
        if((a+b)*(a+b) == i)
        ans[6].push_back(i);
    }
    for(i=0;i<99999999;i++)
    {
        a = i/10000;
        b = i%10000;
        if((a+b)*(a+b) == i)
        ans[8].push_back(i);
    }
    freopen("Quicksome Squares.txt","w",stdout);*/
    char just[23][10] = {"00",
                        "01",
                        "81",
                        "0000",
                        "0001",
                        "2025",
                        "3025",
                        "9801",
                        "000000",
                        "000001",
                        "088209",
                        "494209",
                        "998001",
                        "00000000",
                        "00000001",
                        "04941729",
                        "07441984",
                        "24502500",
                        "25502500",
                        "52881984",
                        "60481729",
                        "99980001"};
    while(scanf("%d",&a) == 1)
    {
        if(a == 2)
            for(i=0;i<3;i++)
                printf("%s\n",just[i]);
        if(a == 4)
            for(i=3;i<8;i++)
                printf("%s\n",just[i]);
        if(a == 6)
            for(i=8;i<13;i++)
                printf("%s\n",just[i]);
        if(a == 8)
            for(i=13;i<22;i++)
                printf("%s\n",just[i]);
    }

    return 0;
}
