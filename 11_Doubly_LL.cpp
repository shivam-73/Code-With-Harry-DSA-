#include<iostream>
using namespace std;
struct node{
int data;
struct node*prev;
struct node*next;
};

void traversal(struct node*head)
{
    struct node*ptr=head;
    cout<<"Forward direction :"<<endl;
    while(ptr->next!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
    cout<<ptr->data<<endl;
    cout<<"REverse direction : "<<endl;
    while(ptr->prev!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->prev;
    }
    cout<<ptr->data<<endl;
}
int main()
{
    struct node*head;
    struct node*second;
    struct node*third;
    struct node*forth;

    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    forth=(struct node*)malloc(sizeof(struct node));

    head->prev=NULL;
    head->data=1;
    head->next=second;

    second->prev=head;
    second->next=third;
    second->data=2;

    third->prev=second;
    third->data=3;
    third->next=forth;

    forth->data=4;
    forth->prev=third;
    forth->next=NULL;

    traversal(head);
    
}