#include<iostream>
using namespace std;

int getMaxIndex(int arr[],int start,int last){
	int max=start;
	for(int i=0;i<=last;i++){
		if(arr[max]<arr[i]){
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

void selectionSort(int arr[],int n){
	for(int i=0;i<n;i++){
		int last=n-i-1;
		int maxIndex=getMaxIndex(arr,0,last);
		swap(arr,maxIndex,last);
	}
}

void printArray(int arr[], int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
}


int main(){
	int arr[5]={-5,4,3,-2,1};
//int arr[1]={0};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	printArray(arr,n);
	selectionSort(arr,n);
	printArray(arr,n);
}
