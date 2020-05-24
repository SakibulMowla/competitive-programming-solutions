#include <stdio.h>

int heap[1000] , heapsize;

void init(void)
{
    heapsize = 0;
    heap[0] = -100000000;
    return;
}

void heap_insert(int element)
{
    int now;
    heap[++heapsize] = element;
    now = heapsize;
    while(element < heap[now/2])
    {
        heap[now] = heap[now/2];
        now /= 2;
    }
    heap[now] = element;
    return;
}

int heap_delete(void)
{
    int to_return,last_element,now,child;
    to_return = heap[1];
    last_element = heap[heapsize--];
    for(now=1 ; now*2<=heapsize ; now = child)
    {
        child = 2 * now;
        if(child != heapsize && heap[child+1] < heap[child])
            child++;

        if(heap[child] < last_element)
            heap[now] = heap[child];
        else
            break;
    }
    heap[now] = last_element;
    return to_return;
}

int main()
{
    int i,j,k,l,m,p,n,num,arr[100],flag;
    flag = 0;
    while(scanf("%d",&n) == 1 && n)
    {
        init();
        if(flag)printf("\n");
        flag = 1;
        for(i=0; i<n; i++)
        {
            scanf("%d",&num);
            heap_insert(num);
        }
        for(i=1; i<=n; i++)
            arr[i] = heap_delete();
        for(i=1; n-i>=5; i++)
            for(j=i+1; n-j>=4; j++)
                for(k=j+1; n-k>=3; k++)
                    for(l=k+1; n-l>=2; l++)
                        for(m=l+1; n-m>=1; m++)
                            for(p=m+1; n-p>=0; p++)
                                printf("%d %d %d %d %d %d\n",arr[i],arr[j],arr[k],arr[l],arr[m],arr[p]);
    }
    return 0;
}
