#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,n,len,c,p,s;
    static k;
    char arr[1000],z;
    scanf("%d%c",&n,&z);
    for(i=0; i<n; i++)
    {
        gets(arr);
        len=strlen(arr);
        if(len%2 == 1)
        {
            printf("No\n");
            continue;
        }
        for(j=0; j<len; j++)
        {
            if(arr[j]==')' || arr[j]==']')
            {
                for(k=j-1; k>=0; k--)
                {
                    s=0;
                    if((arr[j]==')' && arr[k]=='(') || (arr[j]==']' && arr[k]=='['))
                    {
                        s++;
                        arr[j]=arr[k]='0';
                        j++;
                        for(p=k-1; (arr[j]==')' || arr[j]==']')&& (p>=0); p--)
                        {
                            if(arr[j]==')' && arr[p]=='(')
                            {
                                arr[j]=arr[p]='0';
                                j++;
                            }
                            else if(arr[j]==']' && arr[p]=='[')
                            {
                                arr[j]=arr[p]='0';
                                j++;
                            }
                        }
                    }
                    if(s!=0)
                        break;
                }
            }
        }
        c=0;
        for(j=0; j<len; j++)
            if(arr[j]!='0')
                c++;
        if(c!=0)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
