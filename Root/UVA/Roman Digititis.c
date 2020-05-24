#include <stdio.h>

typedef struct{
    int i,v,x,l,c;
}data;

int ni,nv,nx,nl,nc;

void ivx(int n)
{
    switch(n)
    {
        case 0: break;
        case 1: ni+=1; break;
        case 2: ni+=2; break;
        case 3: ni+=3; break;
        case 4: ni+=1;  nv+=1; break;
        case 5: nv+=1; break;
        case 6: ni+=1; nv+=1; break;
        case 7: ni+=2; nv+=1; break;
        case 8: ni+=3; nv+=1; break;
        case 9: ni+=1; nx+=1; break;
        default : break;
    }
    return;
}

void xlc(int n)
{
    switch(n)
    {
        case 0: break;
        case 1: nx+=1; break;
        case 2: nx+=2; break;
        case 3: nx+=3; break;
        case 4: nx+=1; nl+=1; break;
        case 5: nl+=1; break;
        case 6: nx+=1; nl+=1; break;
        case 7: nx+=2; nl+=1; break;
        case 8: nx+=3; nl+=1; break;
        case 9: nx+=1; nc+=1; break;
        case 10: nc+=1; break;
        default : break;
    }
}
int main()
{
    data arr[105];
    int i,num;
    for(i=1;i<=100;i++)
    {
        ivx(i%10);
        xlc(i/10);
        arr[i].i=ni;
        arr[i].v=nv;
        arr[i].x=nx;
        arr[i].l=nl;
        arr[i].c=nc;
    }
    while(scanf("%d",&num)==1 && num)
    {
        printf("%d: %d i, %d v, %d x, %d l, %d c\n",num,arr[num].i,arr[num].v,arr[num].x,arr[num].l,arr[num].c);
    }
    return 0;
}
