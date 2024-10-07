//#include<stdio.h>
//int display(int arr[],int n){
//	for(int i =0;i<n;i++){
//		printf("%d ",arr[i]);
//	}
//	printf("\n");
//}
//void deletion(int arr[],int size , int index){
//	for(int i =index;i<size;i++){
//		arr[i]=arr[i+1];
//	}
//}
//int main()
//{
//	int arr[100], n;
//	printf("Enter the number of elements = ");
//	scanf("%d",&n);
//	for(int i =0;i<n;i++){
//		scanf("%d",&arr[i]);
//	}
//	display(arr ,n);
//	deletion(arr,n ,2);
//	display(arr, n-1);
//	return 0;
//}

#include<stdio.h>
int display(int arr[],int n){
	for(int i =0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void deletion(int arr[],int size , int element){
	int index;
	for(int j =0;j<size;j++){
		if(arr[j]== element){
			index=j;
		}
	}
	for(int i =index;i<size;i++){
		arr[i]=arr[i+1];
	}
}
int main()
{
	int arr[100], n;
	printf("Enter the number of elements = ");
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	display(arr ,n);
	deletion(arr,n ,2);
	display(arr, n-1);
	return 0;
}
