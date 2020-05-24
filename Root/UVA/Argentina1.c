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
    int i,n,j,k,l,u1,u2,v1,v2;
    char z,temp[100];
    scanf("%d%c",&n,&z);
    for(l=0; l<n; l++)
    {
        for(i=0; i<10; i++)
            scanf("%s %d %d",arr[i].name,&arr[i].a,&arr[i].b);
        for(i=0; i<9; i++)
            for(j=i+1; j<10; j++)
                if(arr[i].a < arr[j].a)
                {
                    ch=arr[i];
                    arr[i]=arr[j];
                    arr[j]=ch;
                }
        if(arr[4].a == arr[5].a)
        {
            for(i=0; i<10; i++)
                if(arr[i].a==arr[4].a)
                {
                    u1=i;
                    break;
                }
            for(i=9; i>=0; i--)
                if(arr[i].a==arr[4].a)
                {
                    u2=i;
                    break;
                }
            for(i=u1; i<u2; i++)
                for(j=i+1; j<u2+1; j++)
                    if(arr[i].b > arr[j].b)
                    {
                        ch=arr[i];
                        arr[i]=arr[j];
                        arr[j]=ch;
                    }

            if(arr[4].b == arr[5].b)
            {
                for(i=u1; i<10; i++)
                    if(arr[i].b==arr[4].b)
                    {
                        v1=i;
                        break;
                    }
                for(i=u2; i>=0; i--)
                    if(arr[i].b==arr[4].b)
                    {
                        v2=i;
                        break;
                    }
                for(i=v1; i<v2; i++)
                    for(j=i+1; j<v2+1; j++)
                        if(strcmp(arr[i].name,arr[j].name) > 0)
                        {
                            ch=arr[i];
                            arr[i]=arr[j];
                            arr[j]=ch;
                        }

            }
        }
        for(i=0; i<4; i++)
            for(j=i+1; j<5; j++)
                if(strcmp(arr[i].name,arr[j].name) > 0)
                {
                    strcpy(temp,arr[i].name);
                    strcpy(arr[i].name,arr[j].name);
                    strcpy(arr[j].name,temp);
                }
        for(i=5; i<9; i++)
            for(j=i+1; j<10; j++)
                if(strcmp(arr[i].name,arr[j].name) > 0)
                {
                    strcpy(temp,arr[i].name);
                    strcpy(arr[i].name,arr[j].name);
                    strcpy(arr[j].name,temp);
                }
        printf("Case %d:\n",l+1);
        printf("(%s, %s, %s, %s, %s)\n",arr[0].name,arr[1].name,arr[2].name,arr[3].name,arr[4].name);
        printf("(%s, %s, %s, %s, %s)\n",arr[5].name,arr[6].name,arr[7].name,arr[8].name,arr[9].name);
    }
    return 0;
}
