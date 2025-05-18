#include<iostream>
using namespace std;

int main(){
    int start[] = {1,3,0,5,8,5};
    int end[] = {2,4,6,7,9,9};
    int n = sizeof(start)/sizeof(start[0]);
    int max = 0;
    for(int i = 0;i<n;i++){
        if(end[i]>max){
            max = end[i];
        }
    }
    int arr[max+1];
    for(int i = 0;i<max+1;i++){
        arr[i] = 0;
    }
    for(int i = 0;i<n;i++){
        for(int j = start[i];j<end[i];j++){
            arr[j]++;
        }
    }
    int maxi = 0;
    for(int i = 0;i<max+1;i++){
        if(arr[i]>maxi){
            maxi = arr[i];
        }  
    }
    cout<<maxi;
    return 0;
}