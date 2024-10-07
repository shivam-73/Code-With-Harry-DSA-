#include<iostream>
using namespace std;
struct node{
int data;
struct node * next;
};

void traversal(struct node *ptr){
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
//Case 1
struct node *Deletebeg(struct node*head)
{
    struct node*ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
//Case 2
struct node *Deleteatindex(struct node *head,int index)
{   struct node *ptr=head;
    int i =0;
    while(i<index-1)
    {
        ptr=ptr->next;
        i++;
    }
    struct node *q=ptr->next;
    ptr->next=q->next;
    free(q);
    return head;

}

//Case 3
struct node *Deleteend(struct node * head)
{
    struct node*p=head;
    struct node *q=head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}
//Case 4
struct node *Deleteatvalue(struct node *head,int value)
{   struct node *p=head;
    struct node *q=head->next;
    while(q->data !=value && q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    if(q->data==value)
    {
        p->next=q->next;
        free(q);
    }
    else{
        cout<<"Value does not exist";
    }
    return head;

}
int main()
{   int value;
    cin>>value;
    struct node*head;
    struct node *second;
    struct node *third;
    struct node *forth;

    head=(struct node *)malloc(sizeof(struct node));
    second =(struct node *)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    forth=(struct node*)malloc(sizeof(struct node));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=forth;

    forth->data=40;
    forth->next=NULL;
    traversal(head);
    cout<<"LINKED LIST AFTER DELETION: "<<endl;
    // head=Deletebeg(head);
    // traversal(head);
    // head=Deleteatindex(head,2);
    // traversal(head);
    // head=Deleteend(head);
    // traversal(head);
    head=Deleteatvalue(head,35);
    traversal(head);
}