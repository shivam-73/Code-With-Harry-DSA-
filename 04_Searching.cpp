////=========LINEAR SEARCH ============
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a[5]={1,2,3,4,5};
//	int element=9;
//	int position;
//	int flag=0;
//	for(int i =0;i<5;i++)
//	{
//		if(a[i]==element){
//			position=i+1;
//			flag=1;
//		}
//	}
//	if(flag)
//	{
//	cout<<"The position is: "<<position;
//	}
//	else{
//		cout<<"Element does not found";
//	}
//}
//

//=========BINARY SEARCH=======
// #include<iostream>
// using namespace std;
// int binarySearch(int arr[],int size,int element){
// 	int low,high,mid;
// 	low=0;
// 	high=size-1;
// 	while(low<=high){
// 		mid=(high+low)/2;
// 		if(arr[mid]==element)
// 		{
// 			return mid;
// 		}
// 		else if(arr[mid]<element)
// 		{
// 			low=mid+1;
// 		}
// 		else
// 		{
// 			high=mid-1;
// 		}
// 	}
// 	return -1;
// }
// int main()
// {
// 	int n;
// 	cout<<"Enter size of array: ";
// 	cin>>n;
// 	int a[n];
// 	cout<<"Enter elements of an array: ";
// 	for(int i =0;i<n;i++)
// 	{
// 		cin>>a[i];
// 	}
// 	int element;
// 	cout<<"Enter the element: ";
// 	cin>>element;
// 	int index=binarySearch(a,n,element);
// 	if(index!=-1){
// 	cout<<"The index is "<<index;}
// 	else{
// 		cout<<"Element does not found";
// 	}
// 	return 0;
// }

//------- BINARY SEARCH USING RECURSION ------
#include <iostream>
using namespace std;

int binarySearch(int a[], int t, int l, int r) {
    if (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == t) 
return m;
        if (a[m] < t)
 return binarySearch(a, t, m + 1, r);
        return binarySearch(a, t, l, m - 1);
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int t=5;
    int s = 5;
    int r = binarySearch(arr, t, 0, s - 1);
    if (r != -1) 
cout <<r ;
    else 
cout << "Element not found in the array." ;
    return 0;
}
















