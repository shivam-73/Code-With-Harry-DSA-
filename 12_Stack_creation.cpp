// #include<iostream>
// using namespace std;
// struct stack{
// int size;
// int top;
// int *arr;
// };

// int isFull(struct stack *ptr)
// {
//     if(ptr->top==ptr->size-1)
//     {
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// int isEmpty(struct stack *ptr)
// {
//     if(ptr->top==-1)
//     {
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
// void push(struct stack*ptr,int value)
// {
//     if(isFull(ptr))
//     {
//         cout<<"Stack overflow condition"<<endl;
//     }
//     else{
//         ptr->top=ptr->top+1;
//         ptr->arr[ptr->top]=value;
//         cout<<"Element added successfully"<<endl;
//     }
// }
// void pop(struct stack*ptr)
// {
//     if(isEmpty(ptr))
//     {
//         cout<<"Stack underflow condition"<<endl;
//     }
//     else{
//         cout<<"The popped element is "<<ptr->arr[ptr->top]<<"."<<endl;
//         ptr->top--;
//     }
// }
// void display(struct stack * ptr)
// {
//     if(isEmpty(ptr))
//     {
//         cout<<"Stack is Empty"<<endl;
//     }
//     else{
//         for(int i =ptr->top;i>=0;i--)
//         {
//             cout<<ptr->arr[i]<<" ";
//         }
//     }
// }
// int main()
// {
//     struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
//     sp->size=10;
//     sp->top=-1;
//     sp->arr=(int *)malloc(sp->size*sizeof(struct stack));
//     cout<<"Stack has been successfully created"<<endl;
//     // cout<<isFull(sp)<<endl;
//     // cout<<isEmpty(sp);
//     // push(sp,10);
//     // pop(sp);
//     // cout<<isEmpty(sp)<<endl;
//     push(sp,10);
//     push(sp,20);
//     push(sp,30);
//     push(sp,40);
//     push(sp,50);
//     display(sp);

// }

#include<iostream>
using namespace std;
int power(int base,int expo)
{
    if(expo==0)
    {
        return 1;
    }
    else if(expo==1)
    {
        return base;
    }
    else{
        return base*power(base,expo-1);
    }
}
int main()
{
    int base,expo;
    cin>>base;
    cin>>expo;
    cout<<power(base,expo);
}