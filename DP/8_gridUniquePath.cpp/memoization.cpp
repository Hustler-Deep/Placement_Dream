#include<bits/stdc++.h>
using namespace std;

//T.C.->O(M * N)    S.C.->O((N-1)+(M-1)) + O(M * N)  --> TLE

int countHelper(int i, int j, vector<vector<int>> &dp){
    if(i == 0 && j == 0) return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    int up = countHelper(i-1, j, dp);
    int left = countHelper(i, j-1, dp);

    return dp[i][j] = up + left;    
}

int countWays(int m, int n){
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return countHelper(m-1, n-1, dp);
}

int main(){
    int m=3, n=2;
    cout << countWays(m,n);
}