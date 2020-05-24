#include<stdio.h>
#include<string.h>

typedef struct
{
    char name[100];
    int a,b;
} data;

int main()
{
    data arr[100],ch;
    int i,n,j,k,l,temp,temp1;
    scanf("%d",&k);
    for(l=0; l<k; l++)
    {
        for(i=0; i<2; i++)
            scanf("%s %d %d",arr[i].name,&arr[i].a,&arr[i].b);
        printf("%s %d %d\n",arr[i].name,arr[i].a,arr[i].b);
        ch=arr[0];
        printf("%s %d %d\n",ch.name,ch.a,ch.b);

    }

    return 0;
}
