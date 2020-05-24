#include "stdio.h"
#include "string.h"
#include "string"
#include "iostream"

using namespace std;

int main()
{
    int i,j,k;
    freopen("generate.txt","w",stdout);
    printf("2\n");
    for(k=0; k<2; k++)
    {
        for(i=0; i<20000; i++) printf("a");
        printf(" ");
        for(i=0; i<20000; i++) printf("a");
        printf("\n");
        printf("1000\n");
        for(i=0; i<1000; i++)
        {
            for(j=0; j<40; j++) printf("a");
            printf("\n");
        }
    }
}
