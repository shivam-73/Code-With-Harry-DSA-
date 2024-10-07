#include<iostream>
using namespace std;
struct node{
int data;
struct node*next;
};
void traversal(struct node*ptr)
{
    while(ptr!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
}
int isEmpty(struct node*top)
{
    if(top==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct node*top)
{
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}
struct node *push(struct node*top,int value)
{   if(isFull(top))
{
    cout<<"Stack overflow";
}
else{
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next=top;
    ptr->data=value;
    return ptr;
}
}
int pop(struct node**top)
{
    if(isEmpty(*top))
    {
        cout<<"Stack Empty";
    }
    else{
        struct node*ptr=*top;
        *top=(*top)->next;
        int x=ptr->data;
        free(ptr);
        return x;
    }
}
int peek(struct node*top,int pos)
{
    struct node*ptr=top;
    for(int i=0;i<pos-1 && ptr!=NULL;i++)
    {
        ptr=ptr->next;
    }
    if(ptr==NULL)
    {
        cout<<"Invalid position";
    }
    else{
        cout<<ptr->data<<endl;
    }
}
int stackTop(struct node*top)
{
    if(isEmpty(top))
    {
        return 0;
    }
    else{
        return top->data;
    }
}
int stackBottom(struct node*top)
{
    struct node*ptr=top;
    while((ptr->next)!=NULL)
    {
        ptr=ptr->next;
    }
    return ptr->data;
}
int main()
{
struct node*top=NULL;
top=push(top,10);
top=push(top,20);
top=push(top,30);
traversal(top);
// int x=pop(&top); 
// cout<<"the popped element is "<<x<<endl;;
// peek(top,4);
cout<<"Top element of stack is "<<stackTop(top)<<endl;
cout<<"Bottom element of stack is "<<stackBottom(top)<<endl;
return 0;
}