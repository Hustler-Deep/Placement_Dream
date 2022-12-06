#include<bits/stdc++.h>
using namespace std;

// Recursion -> T.C.-> O(2^N)   S.C.->O(N)
/*
int f(int ind, vector<int> &arr){
    if(ind == 0) return arr[ind];
    if(ind < 0) return 0;

    int pick = arr[ind] + f(ind - 2, arr);
    int notPick = 0 + f(ind - 1, arr);

    return max(pick, notPick);
}
*/

// Memoization -> T.C.-> O(N)   S.C.->O(N) + O(N)
/*
int f(int ind, vector<int> &arr, vector<int> &dp){
    if(ind == 0) return arr[ind];
    if(ind < 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int pick = arr[ind] + f(ind - 2, arr, dp);
    int notPick = 0 + f(ind - 1, arr, dp);

    return dp[ind] = max(pick, notPick);
}
*/

// Tabulation -> T.C.-> O(N)   S.C.->O(N)
/*
int f(int ind, vector<int> &arr, vector<int> &dp){
    dp[0] = arr[0];

    for(int i=1; i<ind; i++){
        int pick = arr[i];
        if(i > 1) pick += dp[i-2];
        int notPick = dp[i-1];

        dp[i] = max(pick, notPick);
    }
    return dp[ind-1];
}
*/

int main(){

    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> dp(n, -1);
    // cout << f(n-1, arr, dp);
    // cout << f(n, arr, dp);

    //Space Optimized -> T.C.->O(N)    S.C.->O(1)
    int prev = arr[0];
    int prev2 = 0;

    for(int i=1; i<n; i++){
        int pick = arr[i];
        if(i > 1) pick += prev2;
        int notPick = prev;

        int curi = max(pick, notPick);
        prev2 = prev;
        prev = curi;
    }
    cout << prev;
    
    return 0;
}