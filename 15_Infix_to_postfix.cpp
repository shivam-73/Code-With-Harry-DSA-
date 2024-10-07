#include<iostream>
#include<string.h>
using namespace std;
struct node{
    char data;
    struct node * next;
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
char stackTop(struct node*top)
{
    if(isEmpty(top))
    {
        return 0;
    }
    else{
        return top->data;
    }
}

int precedence(char ch)
{
    if(ch=='*' || ch=='/')
    {
        return 3;
    }
    else if(ch=='+' ||ch=='-')
    {
        return 2;
    }
    else{
        return 0; 
    }
}
int isOperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
    {
        return 1;
    }
    else{
        return 0;
    }
}
string infixtopostfix(struct node *top ,string infix)
{
    string postfix="";
    int i =0;
    while(infix[i]!='\0')
    {
        char temp=infix[i];
        if(!isOperator(temp))
        {
            postfix+=temp;
            i++;
        }
        else{
            if(precedence(temp)>precedence(stackTop(top)))
            {
                top=push(top,temp);
                i++;
            }
            else{
                char x=pop(&top);
                postfix+=x;
            }
        }
    }
    while(!isEmpty(top))
    {   char y=pop(&top);
        postfix+=y;
    }
    postfix+='\0';
    return postfix;

}
int main()
{
    struct node *top=NULL;
    string infix="x-y/z-k*d";
    cout<<infixtopostfix(top,infix);
    return 0;

}