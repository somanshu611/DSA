#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr,int low,int high) {
    int pivot = arr[high];
    int i = low;
    for(int j=low;j<high;j++) {
        if(arr[j]<pivot) {
            // int temp = arr[i];
            // arr[i] = arr[j];
            // arr[j] = temp;
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[high]);
    // int temp = arr[i];
    // arr[i] = arr[high];
    // arr[high] = temp;
    return i;
}

void quicksort(vector<int> &arr,int low,int high) {
    if(low<high) {
        int pidx = partition(arr,low,high);

        quicksort(arr,low,pidx-1);
        quicksort(arr,pidx+1,high);
    }
    return;
}

int main() {
    vector<int> arr = {6,2,4,3,5,1};
    int n = arr.size();
    quicksort(arr,0,n-1);
    for(auto &x: arr) {
        cout<<x<<" ";
    }
    cout<<endl;


    return 0;
}