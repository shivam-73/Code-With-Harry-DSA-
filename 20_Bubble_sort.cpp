#include<iostream>
using namespace std;
int main()
{   
    int n=5;
    int a[n]={50,3,12,6,7};
    for(int i =0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                    int temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
            }
        }
    }
    for(int i =0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}