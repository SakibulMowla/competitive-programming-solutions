#include <stdio.h>
#include <string.h>

int num;

struct node
{
    int val;
    node *ptr;
};

struct power
{
    node *head,*tail;
    power();
    void push(int x);
    int find(int m);
    void nuller(void);
};

power::power()
{
    head=tail=NULL;
}

void power::push(int x)
{
    node *temp=new node;
    temp->val=x;
    temp->ptr=NULL;
    if(head == NULL)
    {
        head=tail=temp;
    }
    tail->ptr=temp;
    tail=temp;
    if(x==num)
        tail->ptr=head;
}

int power::find(int m)
{
    node *temp,*kick,*prev;
    int cir=m,cut=0;
    prev=tail;
    temp=head;
    while(1)
    {
        if(cir == m)
        {
            cut++;
            cir=1;
            kick=temp;
            prev->ptr=temp->ptr;
            temp=temp->ptr;
            if(num-cut == 1)
                return temp->val;
            delete kick;
            continue;
        }
        cir++;
        prev=temp;
        temp=temp->ptr;
    }
}

void power::nuller(void)
{
    head=tail=NULL;
}

void joseph(int m)
{
    int i,res;
    power p;
    for(i=1;i<=num;i++)
        p.push(i);
    res=p.find(m);
    if(res == 13)
        printf("%d\n",m);
    else
    {
        p.nuller();
        joseph(++m);
    }
    return;
}

int main()
{
    while(scanf("%d",&num) ==1 && num)
        joseph(1);
    return 0;
}
