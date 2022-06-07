#include<bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at,at+n);
    sort(dt,dt+n);
    int i=0,j=0;
    int st=0; // number of stations
    int ans = 0;
    while((i<n) && (j<n)) {
        if(i==j) {
            i++;
            st++;
        } else if(at[i]<=dt[j]) {
            i++;
            st++;
        } else {
            j++;
            st--;
        }
        ans = max(ans,st);
    }
    return ans;
}
int main() {
    return 0;
}