#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000007

vector<int> arr = {1,2,3,4,5,6,7,8};

void print(vector<int> arr) {
    for(auto &c: arr) cout<<c<<" ";
    cout<<'\n';
}
void OnVector() {
    vector<int> v; // empty vector
    swap(arr[0],arr[1]);

    next_permutation(arr.begin(),arr.begin()+3);
    for(auto &c: arr) cout<<c<<" ";
    cout<<'\n';
}
void accumulate() {
    int s = accumulate(arr.begin(),arr.end(),0); // 0 is the initial sum
    double s = accumulate(arr.begin(),arr.end(),0.0); // 0.0 IS VERY IMP, OTHERWISE YOU'LL GET A SIGNED INTEGER OVERFLOW.
    
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    fast_io;
    int t=1;
    // cin>>t;
    while(t--) {
        // accumulate();
        OnVector();
    }
    return 0;
}