#include<iostream>
using namespace std;
int partition(int a[],int low,int high)
{
    int pivot=a[low];
    int i=low+1;
    int j= high;
    int temp;
    do{
        while(a[i]<=pivot)
        {
            i++;
        }
        while(a[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }

    }while(i<j);
    temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}
void quicksort(int a[],int low, int high)
{
    int partitionIndex;
    if(low<high){
    partitionIndex=partition(a,low,high);
    quicksort(a,low,partitionIndex-1);
    quicksort(a,partitionIndex+1,high);
    }
}
int main()
{
    int a[]={3,5,2,13,12,3,2,13,45};
    int n=9;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    quicksort(a,0,n-1);
    for(int i =0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}