#include<iostream>
using namespace std;
void merge(int a[], int mid,int low,int high)
{
    int i=low;
    int j=mid+1;
    int k=low;
    int B[100];
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            B[k]=a[i];
            k++;
            i++;
        }
        else{
            B[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        B[k]=a[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        B[k]=a[j];
        j++;
        k++;
    }
    for(int i=low;i<=high;i++)
    {
        a[i]=B[i];
    }
}

void mergesort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,mid,low,high);
    }
}
int main()
{
    int a[]={11,22,33,44,1,2,3};
    int n=7;
    mergesort(a,0,6);
    for(int i =0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}