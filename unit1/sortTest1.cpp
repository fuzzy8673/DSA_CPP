#include<iostream>
using namespace std;

void printArray(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
}


int getMaxIndex(int arr[],int start,int end){
	int max=start;
	for(int i=start;i<=end;i++){
		if(arr[i]>arr[max]){
			max=i;
		}
	}
	return max;
}

void swap(int arr[],int a,int b){
	int temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}

void selectionSort(int arr[],int n){
	for(int i=0;i<n;i++){
		int last=n-i-1;
		int maxIndex=getMaxIndex(arr,0,last);
		swap(arr,maxIndex,last);
	}
}

void insertionSort(int arr[],int n){
	for(int i=0;i<n-1;i++){
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

int bSearch(int arr[],int n,int target){
	// complete this function
	return -1;
}
int main(){
//	int arr[5]={5,4,3,2,1};
int arr[5]={3,5,2,9,6};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"found at "<<bSearch(arr,n,7)<<endl;
	cout<<"found at "<<bSearch(arr,n,9)<<endl;
	return 0;
}




