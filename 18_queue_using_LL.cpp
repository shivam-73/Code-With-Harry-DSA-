#include<iostream>
using namespace std;
struct node{
    int data;
    struct node*next;
};
struct node*f=NULL;
struct node*r=NULL;
int isEmpty(struct node*f)
{
    if(f==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct node*f)
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
void enqueue(int value)
{   
    if(isFull(f))
    {
        cout<<"Queue overflow";
    }
    else{
        struct node*ptr=(struct node*)malloc(sizeof(struct node));
        ptr->data=value;
        ptr->next=NULL;
        if(f==NULL && r==NULL)
        {
            f=r=ptr;
        }
        else
        {
            r->next=ptr;
            r=ptr;
        }
    }
}
int dequeue()
{
    int value=-1;
    struct node*ptr=f;
    if(isEmpty(f))
    {
        cout<<"Queue is empty";
    }
    else{
        f=f->next;
        value=ptr->data;
        free(ptr);
    }
    return value;
}
void display(struct node*ptr)
{   cout<<"Printing the elements of queue: "<<endl;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
int main()
{

    cout<<endl<<"Dequeing element is : "<<dequeue()<<endl;
    enqueue(10);
    enqueue(20);
    enqueue(30);
    cout<<endl<<"Dequeing element is : "<<dequeue()<<endl;
    cout<<endl<<"Dequeing element is : "<<dequeue()<<endl;
    display(f);
    cout<<endl<<"Dequeing element is : "<<dequeue()<<endl;
     cout<<endl<<"Dequeing element is : "<<dequeue()<<endl;
    return 0;

}