#include<iostream>
using namespace std;
int main()
{
    int n=5;
    int a[n]={12,4,2,9,7};
    for(int i =0;i<n;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            int temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
	for(int i =0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}