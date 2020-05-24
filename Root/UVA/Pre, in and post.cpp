#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>

using namespace std;

stack<char>S;

void tree(int len,char *pre,char *in)
{
    int i,j,k,len1,len2;
    char mid,preL[100],preR[100],inL[100],inR[100];
    mid=pre[0];
    S.push(mid);
    for(i=0;in[i]!=mid;i++)
    {
        inL[i]=in[i];
    }
    inL[i]='\0';
    for(j=0;j<i;j++)
    {
        preL[j]=pre[j+1];
    }
    preL[j]='\0';
    for(k=0,j=i+1;j<len;j++,k++)
    {
        preR[k]=pre[j];
        inR[k]=in[j];
    }
    preR[k]='\0';
    inR[k]='\0';

    len1=strlen(preL);
    len2=strlen(preR);

    if(len2!=0)
        tree(len2,preR,inR);
    if(len1!=0)
        tree(len1,preL,inL);

    return;
}

int main()
{
    int len,test;
    char pre[100],in[100];
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %s %s",&len,&pre,&in);
        tree(len,pre,in);
        while( !S.empty() )
            printf("%c",S.top()),S.pop();
        printf("\n");
    }

    return 0;
}
