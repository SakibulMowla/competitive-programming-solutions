#include <stdio.h>
#include <string.h>
#include <stack>
#include <iostream>

using namespace std;

stack<char>Q;

void tree(char *a,char *b)
{
    int i,j,k,l,len1,len2;
    char mid,left1[100],left2[100],ri1[100],ri2[100];
    mid=a[0];
    Q.push(mid);
    for(i=0;b[i]!=mid;i++)
    {
        left2[i]=b[i];
    }
    left2[i]='\0';
    for(j=0;j<i;j++)
    {
        left1[j]=a[j+1];
    }
    left1[j]='\0';

    len1=strlen(a);
    len2=strlen(b);
    for(k=0,j=i+1;j<len1;j++,k++)
    {
        ri1[k]=a[j];
    }
    ri1[k]='\0';
    for(k=0,j=i+1;j<len2;j++,k++)
    {
        ri2[k]=b[j];
    }
    ri2[k]='\0';
    if(strlen(ri1) != 0)
        tree(ri1,ri2);
    if(strlen(left1) != 0)
        tree(left1,left2);
    return;
}

int main()
{
    int i,j,k,l;
    char s1[100],s2[100],ch;

    while(scanf("%s %s",&s1,&s2) == 2)
    {
        tree(s1,s2);
        while( !Q.empty() )
        {
            ch=Q.top();
            Q.pop();
            printf("%c",ch);
        }
        printf("\n");
    }

    return 0;
}
