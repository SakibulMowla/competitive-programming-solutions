#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;


char arr[100+5];
int len,str[200];

void initializer(void)
{
    int i,k;
    k=1;
    for(i='A';i<='Z';i++)
    {
        str[i]=k++;
        str[i+32]=k++;
    }

    return;
}

void anagram(void)
{
    int n,m,i,j,flag1,flag2;
    char temp;
    flag1=flag2=0;
    for(n=0;n<len-1;n++)
    {
        if(str[arr[n]] < str[arr[n+1]])
        {
            i=n;
            flag1=1;
        }
    }
    for(n=0;n<len;n++)
    {
        if(str[arr[n]] > str[arr[i]])
        {
            j=n;
            flag2=1;
        }
    }
    if(flag1==1 && flag2==1)
    {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        for(n=i+1,m=len-1;n<i+1+(len-i-1)/2;n++,m--)
        {
            temp=arr[n];
            arr[n]=arr[m];
            arr[m]=temp;
        }
        printf("%s\n",arr);
        anagram();
    }
    else
        return;
    return;
}

int main()
{
    initializer();
    int i,j,k,n;
    char temp;
    scanf("%d",&n);
    for(k=0;k<n;k++)
    {
        scanf("%s",arr);
        len=strlen(arr);
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if(str[arr[i]] > str[arr[j]])
                {
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }

        printf("%s\n",arr);
        anagram();
    }
    return 0;
}
