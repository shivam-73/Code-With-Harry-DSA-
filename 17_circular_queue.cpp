#include<iostream>
using namespace std;
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
int isEmpty(struct queue*q)
{
    if(q->f==q->r)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct queue *q)
{
    if((q->r+1)%q->size==q->f)
    {
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(struct queue *q,int value)
{
    if(isFull(q))
    {
        cout<<"Queue overflow";
    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=value;
        cout<<"enque element: "<<value<<endl;
    }
}
int dequeue(struct queue * q)
{   int a=-1;
    if(isEmpty(q))
    {
        cout<<"Queue underflow";
    }
    else{
        q->f=(q->f+1)%q->size;
        a=q->arr[q->f];
        return a;
    }
}
void display(struct queue *q)
{
    while(q->f!=q->r)
    {
        q->f++;
        cout<<q->arr[q->f]<<" ";
    }
}
int main()
{
    struct queue q;
    q.size=4;
    q.f=q.r=0;
    q.arr=(int *)malloc(q.size*sizeof(int));
    // if(isEmpty(&q))
    // {
    //     cout<<"The queue is empty";
    // }
    enqueue(&q,10);
    enqueue(&q,11);
    enqueue(&q,12);
    cout<<"deqeue element: "<<dequeue(&q)<<endl;
    cout<<"deqeue element: "<<dequeue(&q)<<endl;
    cout<<"deqeue element: "<<dequeue(&q)<<endl;
    enqueue(&q,13);
    enqueue(&q,14);
    enqueue(&q,15); 
    if(isEmpty(&q))
    {
        cout<<"queue empty"<<endl;
    }
    if(isFull(&q))
    {
        cout<<"queue full"<<endl;
    }
    return 0;
}