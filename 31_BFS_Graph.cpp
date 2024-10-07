#include<iostream>
using namespace std;
struct queue{
    int size;
    int f;
    int r;
    int  *arr;
};
int isEmpty(struct queue * q)
{
    if(q->f == q->r )
    {
        return 1;
    }
    return 0;
}
int isFull(struct queue * q)
{
    if(q->r == q->size-1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue * q,int data)
{
    if(isFull(q))
    {
        cout<<"The queue is empty!"<<endl;
    }
    else{
        q->r++;
        q->arr[q->r]=data;
    }
}

int dequeue(struct queue *q)
{   
    int a=-1;
    if(isEmpty(q))
    {
        cout<<"The queue is empty !"<<endl;
    }
    else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}

int main()
{
    struct queue q;
    q.size=400;
    q.f=q.r=-1;
    q.arr=(int *)malloc(q.size * sizeof(int));

    //BFS initialization
    int i=1;
    int visited[7]={0,0,0,0,0,0,0};
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    cout<<i;
    visited[i]=1;
    enqueue(&q,i);
    while(!isEmpty(&q))
    {
        int node = dequeue(&q);
        for(int j =0;j<7;j++)
        {
            if(visited[j]==0 && a[node][j]==1)
            {
                cout<<j;
                visited[j]=1;
                enqueue(&q,j);
            }
        }
    }
    return 0;
}