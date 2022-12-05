#include<bits/stdc++.h>
using namespace std;

// Memoization -> T.C.->O(N*K)    S.C.->O(N+N)
/*
int f(int ind, vector<int> &arr, int k, vector<int> &dp){
    if(ind == 0) return 0;
    if(dp[ind] != -1) return dp[ind];

    int minSteps = INT_MAX;
    for(int j=1; j<=k; j++){
        if(ind-j >= 0) {
            int jump = f(ind-j, arr, k, dp) + abs(arr[ind] - arr[ind-j]);
            minSteps = min(minSteps, jump);
        }
    }
    return dp[ind] = minSteps;
}
*/
//Tabulation -> T.C.->O(N * K)     S.C.->O(N)
int f(int n, vector<int> &arr, int k, vector<int> &dp){
    dp[0] = 0;

    for(int i=1; i<n; i++){
        int minSteps = INT_MAX;
        for(int j=1; j<=k; j++){
            if(i-j >= 0) {
                int jump = dp[i-j] + abs(arr[i] - arr[i-j]);
                minSteps = min(minSteps, jump);
            }
        }
        dp[i] = minSteps;
    }
    return dp[n-1];
}
int main(){
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> dp(n, -1);
    // cout << f(n-1, arr, k, dp);
    cout << f(n, arr, k, dp);
}