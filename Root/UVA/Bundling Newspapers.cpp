#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool taken[20];
vector <string> output, newspapers;
int out_size , papers;

void backtrack(int n,int k)
{
    int i;
    if(n == out_size)
    {
        cout<<output[0];
        for(i=1; i<output.size(); i++)
            cout<< ", " << output[i];
        printf("\n");
        return;
    }
    for(i=k; i<papers; i++)
    {
        if( !taken[i] )
        {
            output.push_back(newspapers[i]);
            taken[i] = 1;
            backtrack(n+1,i);
            output.pop_back();
            taken[i] = 0;
        }
    }
}

int main()
{
    int len,i,a,b,test;
    bool blank;
    char arr[100],line[100];
//    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    getchar();
    getchar();
    blank = false;
    while(test--)
    {
        if(blank)
            printf("\n");
        blank = true;
        newspapers.clear();
        output.clear();
        papers = 0;
        gets(arr);
        while(gets(line))
        {
            if(strcmp(line,"\0") == 0)
                break;
            newspapers.push_back(line);
            ++papers;
        }
        len = sscanf(arr,"%d %d",&a,&b);
        if(len == 0)
        {
            for(i=1; i<=papers; i++)
            {
                out_size = i;
                printf("Size %d\n",out_size);
                output.clear();
                backtrack(0,0);
                printf("\n");
            }

        }
        else if(len == 1)
        {
            out_size = a;
            printf("Size %d\n",out_size);
            output.clear();
            backtrack(0,0);
            printf("\n");
        }
        else
        {
            for(i=a; i<=b; i++)
            {
                out_size = i;
                printf("Size %d\n",out_size);
                output.clear();
                backtrack(0,0);
                printf("\n");
            }
        }
    }

    return 0;
}
