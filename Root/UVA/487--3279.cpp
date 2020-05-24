#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

string arr;
string store[100010];
char str[300];

void mapping(void)
{
    str['A']=str['B']=str['C']='2';
    str['D']=str['E']=str['F']='3';
    str['G']=str['H']=str['I']='4';
    str['J']=str['K']=str['L']='5';
    str['M']=str['N']=str['O']='6';
    str['P']=str['R']=str['S']='7';
    str['T']=str['U']=str['V']='8';
    str['W']=str['X']=str['Y']='9';
    return;
}

void size(char *a)
{
    arr.clear();
    for(int i=0; a[i]; i++)
    {
        if( isdigit(a[i]) )arr+=a[i];
        else if( isalpha(a[i]) )arr+=str[a[i]];
    }
    arr.insert(3,"-");
}

int main()
{
    mapping();
    map<string,int>m;
    int t,test,n,i,len,flag;
    char number[1000];
    scanf("%d",&test);
    for(t=0; t<test; t++)
    {
        scanf("%d",&n);
        getchar();
        m.clear();
        len=0;
        for(i=0; i<n; i++)
        {
            gets(number);
            size(number);
            m[arr]++;
            if(m[arr] == 2)store[len++]=arr;
        }
        sort(store,store+len);
        flag=0;
        for(i=0; i<len; i++)
        {
            cout<<store[i]<<" "<<m[store[i]]<<endl;
            flag=1;
        }
        if(flag==0)
            printf("No duplicates.\n");
        if(t<test-1)
            printf("\n");
    }

    return 0;
}
