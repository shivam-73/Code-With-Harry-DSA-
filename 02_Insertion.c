#include<stdio.h>
int main()
{	int arr[100];
	int index, value;
	int n;
	printf("Enter the number of elements in array");
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		printf("Enter the value of arr[%d] = ",i);
		scanf("%d",&arr[i]);
	}
	printf("Enter the index to insert a element = ");
	scanf("%d",&index);
	printf("Enter the value to insert a element = ");
	scanf("%d",&value);
	for(int i=n-1;i>=index;i--){
		arr[i+1]=arr[i];
	}
	arr[index]=value;
	for(int i =0;i<=n;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
