#include<bits/stdc++.h>
using namespace std;

//  Recursion -> T.C. -> O(2^n) S.C.->O(n)
/*
int f(int n){
    if(n <= 1) return n;
    return f(n-1) + f(n-2);
}
*/

// Memoization -> T.C. -> O(n) S.C.->O(n) + O(n)
/*
int f(int n, vector<int> &dp){
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = f(n-1, dp) + f(n-2, dp);
}
*/

int main(){

    int n; cin >> n;
    vector<int> dp(n+1, -1);
    // cout << f(n, dp);

    // Tabulation -> T.C. -> O(n) S.C.->O(n)
    /*
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n];
    */

    //Space Optimized -> T.C. -> O(n) S.C.->O(1)
    int prev2 = 0;
    int prev = 1;

    for(int i=2; i<=n; i++){
        int curi = prev + prev2;
        prev2 = prev;
        prev = curi;
    }
    cout << prev;
}