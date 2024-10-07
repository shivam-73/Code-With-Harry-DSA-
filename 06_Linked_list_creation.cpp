//------ STATIC LINKED LIST ---------

#include<iostream>
using namespace std;
struct node{
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
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    //Allocating memory from the heap
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
    return 0;


}

//-------- DYNAMIC LINKED LIST --------
#include<iostream>
using namespace std;
struct node{
    int data;
    struct node*next;
};
void traversal(struct node *ptr)
{
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
int main()
{
    struct node*head=NULL,*temp;
    int n;
    cin>>n;
    for(int i =0;i<n;i++)
    {
        struct node*ptr=(struct node *)malloc(sizeof(struct node));
        int element;
        cout<<"Enter the data: ";
        cin>>element;
        ptr->data=element;
        ptr->next=NULL;
        if(head==NULL)
        {
            head=temp=ptr;
        }
        else{
            temp->next=ptr;
            temp=ptr;
        }
    }
    traversal(head);
}
