#include<iostream>
using namespace std;

int getMaxIndex(int arr[],int start,int last){
	int max=start;
	for(int i=start;i<=last;i++){
		if(arr[i]>arr[max]){
			max=i;
		}
	}
	return max;
}

void printArray(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
}

void swap(int arr[],int a,int b){
	int temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}

void sel(int arr[],int n){
	for(int i=0;i<n;i++){
		int last=n-i-1;
		int maxIndex=getMaxIndex(arr,0,last);
		swap(arr,last,maxIndex);
	}
}






int main(){
	int arr[5]={5,4,3,2,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	printArray(arr,n);
	sel(arr,n);
	printArray(arr,n);
	return 0;
}
