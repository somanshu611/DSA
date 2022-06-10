#include<bits/stdc++.h>
using namespace std;

// 1 based indexing of node, thus, 
// left child -> 2*i
// right child -> 2*i + 1
// parent -> i/2(floor value)

// class Heap {
//     public : 
//     int arr[10];
//     int size;

//     Heap() {
//         for(int i=0;i<10;i++) arr[i]=-1;
//         size=0;
//     }

//     void insert(int val) { // TC = O(log(n))
//         size++;
//         arr[size]=val;
//         int idx = size;

//         int parent = idx/2;
//         while(idx>1 && arr[parent]<arr[idx]) { // the first condition idx>1 is v.imp here 
//             swap(arr[parent],arr[idx]);
//             idx=parent;
//             parent = idx/2;
//         }
//     }
//     void del() { // Delete Root Node, tc=O(N) 
//         if(size==0) {
//             cout<<"Nothing to delete"<<endl;
//             return;
//         }
//         // step1 : Put last element into first index.
//         arr[1]=arr[size];
//         // step2 : Remove last element
//         arr[size]=-1;
//         size--;
//         // step3 : Take root node to its correct position. 
//         int prnt = 1;
//         while(true) {
//             if((prnt*2<=size) && (arr[prnt]<arr[prnt*2])) {
//                 swap(arr[prnt],arr[prnt*2]);
//                 prnt=prnt*2;
//             } else if( ((prnt*2+1)<=size) && (arr[prnt]<arr[prnt*2+1])) {
//                 swap(arr[prnt],arr[prnt*2+1]);
//                 prnt=prnt*2+1;
//             } else {
//                 return;
//             }
//         }
//     }

//     void print() {
//         for(int i=1;i<=size;i++) {
//             cout<<arr[i]<<" ";
//         }
//         cout<<endl;
//     }
// };

void maxHeapify(int arr[] ,int n,int i) { // C arrays are passed by pointers, no pass by value
    // int arr* is same
    int largest = i;
    int left = (2*i);
    int right = (2*i)+1;
    
    if((left<=n) && (arr[left]>arr[largest])) {
        largest = left;
    }
    if((right<=n) && (arr[right]>arr[largest])) {
        largest = right;
    }
    if(largest!=i) {
        swap(arr[i],arr[largest]);
        // for(int j=1;j<=n;j++)  cout<<arr[j]<<" ";
        // cout<<endl;
        maxHeapify(arr,n,largest);
    }
}
void HeapSort(int arr[],int n) {

    int sz = n;
    while(sz>1) {
        swap(arr[sz],arr[1]);
        sz--;
        maxHeapify(arr,sz,1);
    }
}
 
int main() {
    // Heap h;
    // h.insert(2);
    // h.insert(5);
    // h.insert(7);
    // h.insert(3);
    // h.insert(6);
    // h.print();
    // h.del();
    // h.print();
 
    // Heapify
    // int arr[8]={-1,2,3,6,8,9,4,10};
    // int n = 7;
    // for(int i=(n/2);i>=1;i--) {
    //     // cout<<"Hello"<<endl;
    //     maxHeapify(arr,n,i);
    // }
    // for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
    // cout<<endl;

    // code for minHeapify is very simple. 

    // HeapSort
    int arr[8]={-1,2,3,6,8,9,4,10};
    int n = 7;
    for(int i=(n/2);i>=1;i--) {
        // cout<<"Hello"<<endl;
        maxHeapify(arr,n,i);
    }
    for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
    cout<<endl;

    HeapSort(arr,n);

    for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
    cout<<endl;


    return 0;
}