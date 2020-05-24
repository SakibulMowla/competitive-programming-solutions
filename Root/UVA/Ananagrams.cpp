#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
using namespace std;

int ind[1000+10];

typedef struct{
        char word[30];
}data;

int ananagrams(char arr1[30],char arr2[30])
{
    int i,len1,len2;
    char str1[30],str2[30];
    strcpy(str1,arr1);
    strcpy(str2,arr2);
    len1=strlen(str1);
    len2=strlen(str2);
    if(len1!=len2)
        return 0;
    for(i=0;i<len1;i++)
    {
        str1[i]=toupper(str1[i]);
        str2[i]=toupper(str2[i]);
    }
    sort(str1,str1+len1);
    sort(str2,str2+len2);
    for(i=0;i<len1;i++)
    {
        if(str1[i]!=str2[i])
            break;
    }
    if(i==len1)
    {
        return 1;
    }
    else
        return 0;
}

int main()
{
    data arr[1000+10],result[1000+10];
    int i,j,n,p,res;
    char str[30],temp[30];
    n=0;
    while(scanf("%s",str)==1)
    {
        if(str[0]=='#')
            break;
        strcpy(arr[n++].word,str);
    }
    for(i=0;i<n-1;i++)
    {
        if(ind[i]==0)
        for(j=i+1;j<n;j++)
        {
            res=ananagrams(arr[i].word,arr[j].word);
            if(res==1)
            {
                ind[i]=1;
                ind[j]=1;
            }
        }
    }
    p=0;
    for(i=0;i<n;i++)
    {
        if(ind[i]==0)
        {
            strcpy(result[p++].word,arr[i].word);
        }
    }
    for(i=0;i<p-1;i++)
    {
        for(j=i+1;j<p;j++)
        {
            if(strcmp(result[i].word,result[j].word) > 0)
            {
                strcpy(temp,result[i].word);
                strcpy(result[i].word,result[j].word);
                strcpy(result[j].word,temp);
            }
        }
    }
    for(i=0;i<p;i++)
    printf("%s\n",result[i].word);

    return 0;
}
