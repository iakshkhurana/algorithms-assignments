#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        void merge(vector<int>& arr, int start, int mid, int end) {
            vector<int> temp(end - start + 1);
            int i = start, j = mid + 1, k = 0;
            
            while(i <= mid && j <= end) {
                if(arr[i] <= arr[j]) temp[k++] = arr[i++];
                else temp[k++] = arr[j++];
            }
            
            while(i <= mid) temp[k++] = arr[i++];
            while(j <= end) temp[k++] = arr[j++];
            
            for(int i = 0; i < k; i++) {
                arr[start + i] = temp[i];
            }
        }
        
        void mergeSort(vector<int>& arr, int start, int end) {
            if(start < end) {
                int mid = (start + end) / 2;
                mergeSort(arr, start, mid);
                mergeSort(arr, mid + 1, end);
                merge(arr, start, mid, end);
            }
        }
};

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    Solution sol;
    sol.mergeSort(arr, 0, arr.size() - 1);
    
    for(int num : arr) cout << num << " ";
    cout << endl;
    return 0;
}