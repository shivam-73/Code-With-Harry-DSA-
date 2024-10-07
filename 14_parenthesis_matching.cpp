#include<iostream>
using namespace std;
struct node{
char data;
struct node*next;
};
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
struct node*push(struct node*top,char value)
{
    if(isFull(top))
    {
        cout<<"Stack overflow";
    }
    else{
        struct node*ptr=(struct node*)malloc(sizeof(struct node));
        ptr->data=value;
        ptr->next=top;
        return ptr;
    }
}
char pop(struct node**top)
{
    if(isEmpty(*top))
    {
        cout<<"Stack underflow";
    }
    else{
        struct node*ptr=*top;
        *top=(*top)->next;
        char x=ptr->data;
        free(ptr);
        return x;
    }
}
void traversal(struct node*ptr)
{
    while(ptr!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
}
// int parenthesischeck(struct node*top,string exp)
// {
//     for(int i=0;exp[i]!='\0';i++)
//     {   
//         char temp=exp[i];
//         if(temp=='(')
//         {
//             top=push(top,temp);
//         }
//         else if(temp==')')
//         {
//             if(isEmpty(top))
//             {
//                 return 0;
//             }
//             pop(&top);
//         }        
//     }
//     if(isEmpty(top))
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
int match(char a,char b)
{
    if(a=='('&& b==')')
    {
        return 1;
    }
    if(a=='['&& b==']')
    {
        return 1;
    }
    if(a=='{'&& b=='}')
    {
        return 1;
    }
    return 0;
}
int multiparenthesis(struct node*top,string exp)
{
    for(int i=0;exp[i]!='\0';i++)
    {
        char temp=exp[i];
        if(temp=='(' || temp=='[' || temp=='{')
        {
            top=push(top,temp);
        }
        else if(temp==')'||temp==']'||temp=='}')
        {
            if(isEmpty(top))
            {
                return 0;
            }
            char popped_char=pop(&top);
            if(!match(popped_char,temp))
            {
                return 0;
            }
        }
    }
    if(isEmpty(top))
    {
        return 1;
    }
    else{
        return 0;
    }
}
int main()
{
    struct node*top=NULL;
    string exp="[6-7]((8){(9-8)})";
    if(multiparenthesis(top,exp))
    {
        cout<<"Parenthesis matching";
    }
    else{
        cout<<"Parenthesis not matching ";
    }
    return 0;
}
