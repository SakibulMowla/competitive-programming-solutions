#include "stdio.h"
#include "string.h"
#include "map"
#include "iostream"

using namespace std;

map <char , char> mcc;

int main()
{
//    freopen("1.txt","r",stdin);
    int test,i,t=0;
    char plain[110] , cypher[110] , text[110];
    scanf("%d",&test);
    getchar();
    getchar();
    while(test--)
    {
        mcc.clear();
        gets(plain);
        gets(cypher);
        if(t) printf("\n");
        t = 1;
        for(i=0;i<strlen(plain);i++)
            mcc[ plain[i] ] = cypher[i];
        printf("%s\n",cypher);
        printf("%s\n",plain);
        while(gets(text))
        {
            if(strcmp(text,"\0") == 0) break;
            for(i=0;i<strlen(text);i++)
            {
                if(mcc.find(text[i]) == mcc.end()) printf("%c",text[i]);
                else printf("%c",mcc[ text[i] ]);
            }
            printf("\n");
        }

    }

    return 0;
}
