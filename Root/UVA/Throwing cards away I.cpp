#include <stdio.h>
#include <string.h>
#include <math.h>

int arr[60];
int rear,num;
void pop()
{
    --rear;
    return;
}

void print()
{
    printf(" %d",arr[rear-1]);
    if(num>1)
        printf(",");
    --num;
    pop();
    return;
}

void push(int item)
{
    arr[rear++]=item;
    return;
}

int main()
{
    int cards,i,count;
    while(scanf("%d",&cards)==1 && cards)
    {
        rear=0;
        num=cards;
        i=1;
        count=0;
        printf("Discarded cards:");
        while(num>0)
        {
            if(i>cards)
            i%=cards;
            push(i);
            if(count==0)
            {
                print();
                ++count;
            }
            else
                --count;
            i++;
        }
        printf("\n");

        printf("Remaining card: %d\n",arr[2]);
    }
    return 0;
}
