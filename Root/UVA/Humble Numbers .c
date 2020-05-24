#include<stdio.h>

int main()
{
    long int humble[5843],h,a,b,c,d,A,B,C,D,n;
    a=b=c=d=1;
    humble[1]=1;
    h=2;
    while(h<=5842)
    {
        A=2*humble[a];
        B=3*humble[b];
        C=5*humble[c];
        D=7*humble[d];
        if(A<B && A<C && A<D)
        {
            humble[h]=A;
            h++;
            a++;
        }
        else if(B<A && B<C && B<D)
        {
            humble[h]=B;
            h++;
            b++;
        }
        else if(C<A && C<B && C<D)
        {
            humble[h]=C;
            h++;
            c++;
        }
        else if(D<A && D<B && D<C)
        {
            humble[h]=D;
            h++;
            d++;
        }
        else if(A==B) a++;
        else if(A==C) a++;
        else if(A==D) a++;
        else if(B==C) b++;
        else if(B==D) b++;
        else if(C==D) c++;
    }

    while(scanf("%ld",&n)==1)
    {
        if(n==0) break;
        if(n%100==11 || n%100==12 || n%100==13)
            printf("The %ldth humble number is %ld.\n",n,humble[n]);
        else if(n%10==1)
            printf("The %ldst humble number is %ld.\n",n,humble[n]);
        else if(n%10==2)
            printf("The %ldnd humble number is %ld.\n",n,humble[n]);
        else if(n%10==3)
            printf("The %ldrd humble number is %ld.\n",n,humble[n]);
        else
            printf("The %ldth humble number is %ld.\n",n,humble[n]);

    }

    return 0;
}
