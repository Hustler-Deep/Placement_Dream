#include<bits/stdc++.h>
using namespace std;
/*
//Memoization -> T.C.-.O(N)    S.C.->O(N + N)
int solve(int ind, vector<int> &arr, vector<int> &dp){
    if(ind == 0) return 0;
    if(dp[ind] != -1) return dp[ind];
    int ss = INT_MAX;
    int fs = solve(ind-1, arr, dp) + abs(arr[ind] - arr[ind-1]);
    if(ind > 1) ss = solve(ind-2, arr, dp) + abs(arr[ind] - arr[ind-2]);
    return dp[ind] = min(fs, ss);
}
*/
int main(){
    vector<int> arr{30, 10, 60, 10, 60, 50};
    int n = arr.size();
    vector<int> dp(n, -1);
    // cout << solve(n-1, arr, dp);

    // Tabulation -> T.C.-.O(N)    S.C.->O(N)
    // dp[0] = 0;
    // for(int ind=1; ind<n; ind++){
    //     int ss = INT_MAX;
    //     int fs = dp[ind-1] + abs(arr[ind] - arr[ind-1]);
    //     if(ind > 1) ss = dp[ind-2] + abs(arr[ind] - arr[ind-2]);

    //     dp[ind] = min(fs, ss);
    // }
    // cout << dp[n-1];

    // Space Optimized -> T.C.-.O(N)    S.C.->O(1)
    int prev=0;
    int prev2=0;
    for(int i=1;i<n;i++){
        
        int ss = INT_MAX;
        int fs= prev + abs(arr[i]-arr[i-1]);
        if(i>1)
            ss = prev2 + abs(arr[i]-arr[i-2]);
    
        int cur_i=min(fs, ss);
        prev2=prev;
        prev=cur_i;
        
  }
  cout<<prev;
}