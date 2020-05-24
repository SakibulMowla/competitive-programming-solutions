#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

int arr[2010];
int str[130];
int main()
{
    int n,i,j,k,c,len;
    char line[2010],z;
    arr[0]=arr[1]=1;
    for(i=4; i<2010; i+=2)
        arr[i]=1;
    for(i=3; i<sqrt(2010); i+=2)
        if(arr[i]==0)
            for(j=i*i; j<2010; j+=i*2)
                arr[j]=1;

    scanf("%d%c",&n,&z);
    for(k=0;k<n;k++)
    {
        gets(line);
        len=strlen(line);
        for(i=0;i<len;i++)
        {
            str[line[i]]++;
        }
        c=0;
        printf("Case %d: ",k+1);
        for(i=0;i<130;i++)
        {
            if(str[i]>0 && arr[str[i]]==0)
            {
                printf("%c",i);
                c=1;
            }
        }
        if(c==0)
            printf("empty");
        printf("\n");
        for(i=0;i<130;i++)
            str[i]=0;
    }

    return 0;
}
