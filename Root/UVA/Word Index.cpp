// 417 - Word Index

#include <stdio.h>
#include <string.h>

#define max 84000

char arr[max][10];
int main()
{
    int i,j,k,p,l,m,n,index,len;
    char str[10];
    k=0;
    index=0;

    for(i='a'; i<='z'; i++)
    {
        arr[k][index]=i;
        arr[k][index+1]='\0';
        k++;
    }

    for(i='a'; i<'z'; i++)
    {
        for(j=i+1; j<='z'; j++)
        {
            arr[k][index]=i;
            arr[k][index+1]=j;
            arr[k][index+2]='\0';
            k++;
        }
    }

    for(i='a'; i<'z'-1; i++)
    {
        for(j=i+1; j<'z'; j++)
        {
            for(p=j+1; p<='z'; p++)
            {
                arr[k][index]=i;
                arr[k][index+1]=j;
                arr[k][index+2]=p;
                arr[k][index+3]='\0';
                k++;
            }
        }
    }

    for(i='a'; i<'z'-2; i++)
    {
        for(j=i+1; j<'z'-1; j++)
        {
            for(p=j+1; p<'z'; p++)
            {
                for(l=p+1; l<='z'; l++)
                {
                    arr[k][index]=i;
                    arr[k][index+1]=j;
                    arr[k][index+2]=p;
                    arr[k][index+3]=l;
                    arr[k][index+4]='\0';
                    k++;
                }
            }
        }
    }

    for(i='a'; i<'z'-3; i++)
    {
        for(j=i+1; j<'z'-2; j++)
        {
            for(p=j+1; p<'z'-1; p++)
            {
                for(l=p+1; l<'z'; l++)
                {
                    for(m=l+1; m<='z'; m++)
                    {
                        arr[k][index]=i;
                        arr[k][index+1]=j;
                        arr[k][index+2]=p;
                        arr[k][index+3]=l;
                        arr[k][index+4]=m;
                        arr[k][index+5]='\0';
                        k++;
                    }
                }
            }
        }
    }

    while(gets(str))
    {
        n=0;
        len=strlen(str);
        if(len==1)
        {
            for(i=0;i<=25;i++)
            {
                if(strcmp(str,arr[i]) == 0)
                {
                    n=i+1;
                    break;
                }
            }
        }

        else if(len==2)
        {
            for(i=26;i<=350;i++)
            {
                if(strcmp(str,arr[i]) == 0)
                {
                    n=i+1;
                    break;
                }
            }
        }

        else if(len==3)
        {
            for(i=351;i<=2950;i++)
            {
                if(strcmp(str,arr[i]) == 0)
                {
                    n=i+1;
                    break;
                }
            }
        }

        else if(len==4)
        {
            for(i=2951;i<=17900;i++)
            {
                if(strcmp(str,arr[i]) == 0)
                {
                    n=i+1;
                    break;
                }
            }
        }

        else if(len==5)
        {
            for(i=17901;i<=83680;i++)
            {
                if(strcmp(str,arr[i]) == 0)
                {
                    n=i+1;
                    break;
                }
            }
        }
        printf("%d\n",n);
    }

    return 0;
}
