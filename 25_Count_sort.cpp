#include<iostream>
using namespace std;
int maximum(int a[],int n)
{
    int max=a[0];
    for(int i =1;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    return max;
}
void countsort(int *a,int n)
{   int i,j;
    int max=maximum(a,n);
    int *count=(int *)malloc((max+1)*sizeof(int));
    for(i=0;i<max+1;i++)
    {
        count[i]=0;
    }
    for(int i =0;i<n;i++)
    {
        count[a[i]]=count[a[i]]+1;
    }
    i=0; //counter for count array
    j=0; //counter for given array
    while(i<=max)
    {
        if(count[i]>0)
        {
            a[j]=i;
            count[i]=count[i]-1;
            j++;
        }
        else{
            i++;
        }
    }
}
int main()
{
    int a[]={9,1,4,14,4,15,16};
    int n=7;
    countsort(a,7);
    for(int i =0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}