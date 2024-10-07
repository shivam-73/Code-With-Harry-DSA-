#include<iostream>
using namespace std;
struct node{
    int data;
    struct node*next;
};
void traversal(struct node*head)
{
    struct node*ptr=head;
    do{
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }while(ptr!=head);
}
struct node*InsertatFirst(struct node*head,int element)
{
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node*p=head->next;
    ptr->data=element;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    return ptr;

}
int main()
{
    struct node*head;
    struct node*second;
    struct node*third;
    struct node *forth;
    
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    forth=(struct node*)malloc(sizeof(struct node));

    head->data=4;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=1;
    third->next=forth;

    forth->data=6;
    forth->next=head;
    cout<<"Linked list before traversal "<<endl;
    traversal(head);
    head=InsertatFirst(head,50);
    cout<<endl<<"Linked list after insertion"<<endl;
    traversal(head);

    return 0;
}