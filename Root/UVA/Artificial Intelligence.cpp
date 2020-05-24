#include "stdio.h"
#include "string.h"
#include "string"
#include "vector"
#include "iostream"

using namespace std;

int main()
{
    int t,test,len;
    double p,u,i,d;
    bool P,U,I;
    char arr[1000],con,pre,unit,ch;
//    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    for(t=1; t<=test; t++)
    {
        P = U = I = false;
        scanf(" %[^\n]",arr);
        char *tok = strtok(arr," ");
        while(tok != NULL)
        {
            if(tok[1]=='=')
            {
                len = sscanf(tok,"%c %c %lf %c %c",&con,&ch,&d,&pre,&unit);
                if(len == 5)
                {
                    if(pre == 'm')
                        d /= 1000;
                    if(pre == 'k')
                        d *= 1000;
                    if(pre == 'M')
                        d *= 1000000;
                }
                if(tok[0]=='P')
                {
                    p = d;
                    P = true;
                }
                if(tok[0]=='U')
                {
                    u = d;
                    U = true;
                }
                if(tok[0]=='I')
                {
                    i = d;
                    I = true;
                }
            }
            tok = strtok(NULL," ");
        }
        printf("Problem #%d\n",t);
        if(P && U)
        {
            i = p / u;
            printf("I=%.2lfA\n",i);
        }
        if(U && I)
        {
            p = u * i;
            printf("P=%.2lfW\n",p);
        }
        if(P && I)
        {
            u = p / i;
            printf("U=%.2lfV\n",u);
        }
        printf("\n");
    }

    return 0;
}
