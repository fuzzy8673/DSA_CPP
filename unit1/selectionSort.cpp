#include<iostream>
using namespace std;

int getMaxIndex(int arr[],int start,int last){
	int max=start;
	for(int i=0;i<last;i++){
		if(arr[i]>arr[max]){
			max=i;
		}
	}
	return max;
}

void swap(int arr[],int first,int second){
	int temp=arr[first];
	arr[first]=arr[second];
	arr[second]=temp;
}

void printArray(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
}

void selectionSort(int arr[],int n){
	for(int i=0;i<n;i++){
		int last=n-i-1;
		int maxIndex=getMaxIndex(arr,0,last);
		swap(arr,last,maxIndex);
	}
}

void insertionSort(int arr[],int n){
	
	for (int i=0;i<n-1;i++){
		for(int j=i+1;j>0;j--){
			if(arr[j]<arr[j-1]){
				swap(arr,j,j-1);
			}
			else{
				break;
			}
		}
	}
}

int main(){
//	int arr[6]={6,5,40,3,2,1};
	int arr[5]={5,4,3,2,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	printArray(arr,n);
//	selectionSort(arr,n);
insertionSort(arr,n);
	printArray(arr,n);
	
	return 0;
}
