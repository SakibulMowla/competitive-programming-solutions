#include<stdio.h>
#include<string.h>

char con[10000000],ini[1050000];

int main()
{
    int i,j,k,l,n,m,len,c;

    char arr[10],z;

    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d%c",&m,&z);
        for(j=0; j<m; j++)
        {
            gets(ini);
            len=strlen(ini);
            l=0;
            for(k=0; k<len && l<7; k++)
            {
                if(ini[k]>='A' && ini[k]<='Z')
                {
                    if(ini[k]=='A' || ini[k]=='B' || ini[k]=='C')
                        arr[l]='2';
                    else if(ini[k]=='D' || ini[k]=='E' || ini[k]=='F')
                        arr[l]='3';
                    else if(ini[k]=='G' || ini[k]=='H' || ini[k]=='I')
                        arr[l]='4';
                    else if(ini[k]=='J' || ini[k]=='K' || ini[k]=='L')
                        arr[l]='5';
                    else if(ini[k]=='M' || ini[k]=='N' || ini[k]=='O')
                        arr[l]='6';
                    else if(ini[k]=='P' || ini[k]=='R' || ini[k]=='S')
                        arr[l]='7';
                    else if(ini[k]=='T' || ini[k]=='U' || ini[k]=='V')
                        arr[l]='8';
                    else if(ini[k]=='W' || ini[k]=='X' || ini[k]=='Y')
                        arr[l]='9';
                    l++;
                }
                else if(ini[k]>='0'&& ini[k]<='9')
                {
                    arr[l]=ini[k];
                    l++;
                }
            }
            arr[l]='\0';
            con[atol(arr)]++;

        }
        c=0;
        for(k=0; k<10000000; k++)
        {
            if(con[k]>1)
            {
                printf("%03d-%04d %d\n",k/10000,k%10000,con[k]);
                c++;
            }
        }
        if(c==0)
            printf("No duplicates.\n");
        if(i<n-1)
            printf("\n");
        for(k=0; k<10000000; k++)
            con[k]=0;
    }

    return 0;
}
