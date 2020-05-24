#include <stdio.h>
#include <string.h>

int heap[100];
int heapsize;

void insert(int element)
{
    heap[++heapsize] = element;
    int now = heapsize;
    while( (now/2)>0 &&  (element < heap[now/2]) )
    {
        heap[now] = heap[now/2];
        now /= 2;
    }
    heap[now] = element;
}

int Delete(void)
{
    int to_return,last_element,now,child;
    to_return = heap[1];
    last_element = heap[heapsize--];
    for(now=1;now*2<=heapsize;now=child)
    {
        child = 2 * now;
        if(child < heapsize && heap[child+1] < heap[child])
            child++;

        if(heap[child] < last_element)
            heap[now] = heap[child];
        else break;
    }
    heap[now] = last_element;
    return to_return;
}

int main()
{
    int i,n,num,arr[100];
    while(scanf("%d",&n) == 1 && n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&num);
            insert(num);
        }
        heapsize = 0;
        for(i=1;i<=n;i++)
            printf("%d ",heap[i]);
        printf("\n");
        for(i=0;i<n;i++)
            printf("%d ",Delete());
        printf("\n");
    }

    return 0;
}
