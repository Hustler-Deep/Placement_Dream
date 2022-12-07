#include<bits/stdc++.h>
using namespace std;

//Space Optimized -> T.C.->O(N)    S.C.->O(1)
long long int f(vector<int> &arr){
    int n = arr.size();
    long long int prev = arr[0];
    long long int prev2 = 0;

    for(int i=1; i<n; i++){
        long long int pick = arr[i];
        if(i > 1) pick += prev2;
        long long int notPick = prev;

        long long int curi = max(pick, notPick);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

long long int robStreet(int n, vector<int> &arr){
    vector<int> arr1, arr2;
    if(n==1) return arr[0];

    for(int i=0; i<n; i++){
        if(i != 0) arr1.push_back(arr[i]);
        if(i != n-1) arr2.push_back(arr[i]);
    }
    long long int ans1 = f(arr1);
    long long int ans2 = f(arr2);

    return max(ans1, ans2);
}

int main(){

    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << robStreet(n, arr);
    
    return 0;
}