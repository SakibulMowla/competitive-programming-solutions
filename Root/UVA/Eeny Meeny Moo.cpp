#include <stdio.h>
#include <string.h>

int num;

struct node
{
    int val;
    node *ptr;
};

struct joseph
{
    node *head,*tail;
    joseph();
    void push(int x);
    int find(int m);
    void nuller(void);
};

void joseph::nuller(void)
{
    head=tail=NULL;
}

joseph::joseph()
{
    head=tail=NULL;
}

void joseph::push(int x)
{
    node *temp=new node;
    temp->val=x;
    temp->ptr=NULL;
    if(head==NULL)
    {
        head=tail=temp;
        return;
    }
    tail->ptr=temp;
    tail=temp;
    if(x==num)
        tail->ptr=head;
}

int joseph::find(int m)
{
    node *temp=head,*kick,*prev;
    int cut;
    int cir=m;
    prev=tail;
    temp=head;
    cut=0;
    while(1)
    {
        if(cir==m)
        {
            kick=temp;
            prev->ptr=temp->ptr;
            temp=temp->ptr;
            delete kick;
            cut++;
            cir=1;
            if(num-cut==1)
                return temp->val;

        }
        prev=temp;
        temp=temp->ptr;
        cir++;
    }
}

void moo(int m)
{
    int i,res;
    joseph j;
    for(i=1;i<=num;i++)
        j.push(i);
    res=j.find(m);
    if(res==2)
        printf("%d\n",m);

    else
    {
        j.nuller();
        moo(++m);
    }

    return;
}

int main()
{
    while(scanf("%d",&num) ==1 && num)
        moo(2);

    return 0;
}
