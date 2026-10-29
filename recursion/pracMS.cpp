#include<iostream>
#include<vector>
using namespace std;

vector<int> merge(vector<int> a,vector<int> b){
    vector<int> mix(a.size()+b.size());
    int i=0;
    int j=0;
    int k=0;

    while(i<a.size() && j<b.size()){
        if (a[i]<b[j])
        {
            mix[k]=a[i];
            i++;
        }
        else{
            mix[k]=b[j];
            j++;
        }
        k++;
        
    }

    while (i<a.size())
    {
        mix[k]=a[i];
        i++;
        k++;
    }
    while (i<b.size())
    {
         mix[k]=b[j];
        j++;
        k++;
    }

    return mix;
    
}

vector<int> mergeSort(vector<int> arr){
    if (arr.size()<=0)
    {
        return arr;
    }

    int mid=arr.size()/2;
    vector<int> left(arr.begin(),arr.begin()+mid);  // 0 - 0+3= 3
    vector<int> right(arr.begin()+mid,arr.end());

    left=mergeSort(left);
    right=mergeSort(right);

    return merge(left,right);
    
}