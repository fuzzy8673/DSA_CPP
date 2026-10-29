#include <iostream>
using namespace std;

int search(int arr[],int n,int target){
	int i;
	for(i=0;i<n;i++){
		if(arr[i]==target){
			return i;
		}
	}
	return -1;
}


int main(){
	int arr[7]={2,4,8,9,6,1,7};
	int n=sizeof(arr);
	cout << "found at " << search(arr, n, 1) << endl;
    cout << "found at " << search(arr, n, 10) << endl;
	
	return 0;
}


