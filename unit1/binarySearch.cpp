#include<iostream>
using namespace std;

int binarySearch(int arr[],int n,int target){
	int start=0;
	int end=n-1;
	
	while(start<= end){
		int mid=(start+end)/2;
		if(target<arr[mid]){
			end=mid-1;
		}
		else if(target>arr[mid]){
			start=mid+1;
		}
		else{
			return mid;
		}
	}
	return -1;
}


int main(){
	int arr[7] = {1,2,4,6,7,8,9};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "found at " << binarySearch(arr, n, 6) << endl;
    cout << "found at " << binarySearch(arr, n, 10) << endl;
}
