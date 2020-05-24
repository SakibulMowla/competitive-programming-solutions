#include "stdio.h"
#include "string.h"
#include "string"
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

struct data
{
    char name[100];
    char dir[100];
};

int main()
{
    int n,test,i,ind;
    data arr[100];
    char s[100];
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s %s %[^\n]",arr[i].dir,s,arr[i].name);
        }
        ind = 0;
        for(i=n-1;i>=0;i--)
        {
            if(ind == 0) printf("Begin on ");
            else if(ind == 1) printf("Left on ");
            else if(ind == -1) printf("Right on ");
            printf("%s\n",arr[i].name);
            if(strcmp("Right",arr[i].dir) == 0) ind = 1;
            else if(strcmp("Left",arr[i].dir) == 0) ind = -1;
        }
        printf("\n");
    }

    return 0;
}
