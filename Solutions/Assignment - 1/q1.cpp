#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>arr, int target){
    int i = 0 , j = arr.size() - 1;
    while(i<=j){
        int mid = (i+j) >> 1;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            j = mid - 1;
        }
        else{
            i = mid + 1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {2,5,8,12,16,23,38,56,72,91};
    int n = arr.size();
    int ans = binarySearch(arr , 23);
    cout<<ans<<endl;
}