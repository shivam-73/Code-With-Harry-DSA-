#include<iostream>
using namespace std;
int main()
{
    int n=5;
    int a[n]={12,7,2,9,18};
    for( int i=1;i<=n-1;i++)
    {
        int temp=a[i];
        int j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    for(int i =0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}