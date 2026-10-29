#include<iostream>
using namespace std;

void printArray(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		cout<< arr[i]<<" "<<endl;
	}
}

int main(){
	int arr[6];
	printArray(arr,6);
	cout<<"enter 6 elements"<<endl;
	int i;
	for(i=0;i<6;i++){
		cin>>arr[i];
	}
	cout<<"Your new array is"<<endl;
	printArray(arr,6);
	return 0;
}


