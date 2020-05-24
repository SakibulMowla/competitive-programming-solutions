#include<stdio.h>
#include<string.h>
int main()
{
    char z,a[1000];
    long long int k,j,len,i,sum;
    scanf("%lld%c",&k,&z);
    for(j=0; j<k; j++)
    {
        gets(a);

            sum=0;

            len=strlen(a);

            for(i=0; i<len; i++)
            {
                if(toupper(a[i])=='A'||toupper(a[i])=='D'||toupper(a[i])=='G'||toupper(a[i])=='J'||toupper(a[i])=='M'||toupper(a[i])=='P'||toupper(a[i])=='T'||toupper(a[i])=='W'||toupper(a[i])==' ')
                    sum+=1;

                else if(toupper(a[i])=='B'||toupper(a[i])=='E'||toupper(a[i])=='H'||toupper(a[i])=='K'||toupper(a[i])=='N'||toupper(a[i])=='Q'||toupper(a[i])=='U'||toupper(a[i])=='X')
                    sum+=2;

                else if(toupper(a[i])=='C'||toupper(a[i])=='F'||toupper(a[i])=='I'||toupper(a[i])=='L'||toupper(a[i])=='O'||toupper(a[i])=='R'||toupper(a[i])=='V'||toupper(a[i])=='Y')
                    sum+=3;

                else if(toupper(a[i])=='S'||toupper(a[i])=='Z')
                    sum+=4;
            }

            printf("Case #%lld: %lld\n",j+1,sum);

    }
    return 0;
}
