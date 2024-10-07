#include <iostream>
using namespace std;
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isEmpty(struct queue *q)
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
    if(q->r==q->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(struct queue *q, int value)
{
    if (isFull(q))
    {
        cout << "Queue Overflow";
    }
    else
    {
        q->r++;
        q->arr[q->r]=value;
    }
}
int dequeue(struct queue *q)
{   int a=-1;
    if(isEmpty(q))
    {
        cout<<"This queue is empty";
    }
    else{
        q->f++;
        a=q->arr[q->f];
        return a;
    }
}
void display(struct queue *q)
{
    while(q->f!=q->r)
    {  
        q->f++;
        cout<<q->arr[q->f]<<endl;
        
    }
}
int main()
{
    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q,10);
    enqueue(&q,12);
    cout<<"The dequeuing element is: "<<dequeue(&q)<<endl;
    cout<<"The dequesing element is: "<<dequeue(&q)<<endl;
    if(isEmpty(&q))
    {
        cout<<"THe queue is empty";
    };
    display(&q);
    return 0;
}