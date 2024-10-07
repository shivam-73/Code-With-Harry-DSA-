#include<iostream>
using namespace std;
struct node
{
int data;
struct node * next;
};
void traversal(struct node *ptr)
{
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
struct node *InsertBeg(struct node*head,int element){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=element;
    ptr->next=head;
    return ptr;
}
struct node *Insertatindex(struct node*head,int element,int index)
{
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p=head;
    int i =0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=element;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
struct node *Insertatend(struct node*head,int element)
{
    struct node*ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=element;
    struct node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
struct node *Insertafternode(struct node *head,struct node *pre,int element)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=element;
    ptr->next=pre->next;
    pre->next=ptr;
    return head;
}
int main()
{   int data=40;
    struct node*head;
    struct node *second;
    struct node *third;

    head=(struct node *)malloc(sizeof(struct node));
    second =(struct node *)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=NULL;
    traversal(head);
    cout<<"LINKED LIST AFTER INSESRTION"<<endl;
    // head=InsertBeg(head,data);
    // traversal(head);

    // head=Insertatend(head,data);
    // traversal(head);
    head=Insertafternode(head,second,40);
    traversal(head);
    return 0;

}
