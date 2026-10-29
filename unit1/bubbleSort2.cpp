#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n){
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

int main(){
	
	int arr[10]={8,2,7,9,23,5,3,6,4,0};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"before sorting"<<endl;
	printArray(arr,n);
	cout<<"after sorting"<<endl;
	bubbleSort(arr,n);
	
	printArray(arr,n);
	
	return 0;
}
