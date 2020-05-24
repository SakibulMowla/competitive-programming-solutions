#include<stdio.h>
#include<string.h>

int arr1[26];
int arr2[26];

int main()
{
    char str1[1001],str2[1001];
    int i,j,k,l[26],len1,len2;
    while(gets(str1) && gets(str2))
    {
        len1=strlen(str1);
        len2=strlen(str2);
        for(i=0;i<len1;i++)
            arr1[str1[i]-'a']++;

        for(i=0;i<len2;i++)
            arr2[str2[i]-'a']++;

        for(i=0;i<26;i++)
        {
            if(arr1[i] <= arr2[i])
                l[i]=arr1[i];
            else
                l[i]=arr2[i];
        }

        for(i=0;i<26;i++)
        {
            if(l[i]>0)
            for(j=0;j<l[i];j++)
                printf("%c",i+'a');
        }
        printf("\n");

        for(i=0;i<26;i++)
            {arr1[i]=0;
            arr2[i]=0;}
    }
    return 0;
}
