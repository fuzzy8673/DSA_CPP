#include<iostream>
using namespace std;

void bSort(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		int j;
		for(j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
void printArray(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		cout<< arr[i]<<" "<<endl;
	}
}

int largest(int arr[], int n){
	int ans=arr[0];
	int i;
	for(i=1;i<n;i++){
		if(arr[i]>ans){
			ans=arr[i];
		}
	}
	return ans;
}

int main(){
	int arr[7] = {6,7,8,9,1,2,4}; 
	int n = sizeof(arr) / sizeof(arr[0]);
	cout<<"Before sorting"<<endl;
	printArray(arr,n);
	cout<<"After sorting"<<endl;
	bSort(arr,n);
	printArray(arr,n);
	
	// find the largest element of an array
}














