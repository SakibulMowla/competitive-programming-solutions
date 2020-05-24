#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
    long int n,c1;
    char i,ch,prech,p,s[2]= {'a','y'};

    prech=' ';
    c1=0;
    while (scanf("%c", &i)!= '\n')
    {

        if((toupper(i)=='B' || toupper(i)=='C' || toupper(i)=='D' || toupper(i)=='F' || toupper(i)=='G' || toupper(i)=='H' || toupper(i)=='J' || toupper(i)=='K' || toupper(i)=='L' || toupper(i)=='M' || toupper(i)=='N' || toupper(i)=='P' || toupper(i)=='Q' || toupper(i)=='R' || toupper(i)=='S' || toupper(i)=='T' || toupper(i)=='V' || toupper(i)=='W' || toupper(i)=='X' || toupper(i)=='Y' || toupper(i)=='Z' ) && (toupper(prech)<'A' || toupper(prech)>'Z'))
        {
            p=i;
            c1=1;
        }
        else if((toupper(i)<'A' || toupper(i)>'Z') && i!=0 && (toupper(prech)>='A' && toupper(prech)<='Z'))
        {
            if(c1==1)
            {
                printf("%c",p);
                printf("%c%c",s[0],s[1]);
                printf("%c",i);
                c1=0;
            }
            else
            {
                printf("%c%c",s[0],s[1]);
                printf("%c",i);
            }
        }
        else
            printf("%c",i);

        prech=i;
    }
    printf("\n");


    return 0;
}
