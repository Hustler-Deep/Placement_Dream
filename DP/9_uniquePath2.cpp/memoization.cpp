#include<bits/stdc++.h>
using namespace std;

//T.C.->O((M * N))    S.C.->O((N-1)+(M-1)) + O(M * N)

int mazeSolve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp){
    if(i > 0 && j > 0 && mat[i][j] == -1) return 0;
    if(i == 0 && j == 0) return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int up = mazeSolve(i-1, j, mat, dp);
    int left = mazeSolve(i, j-1, mat, dp);

    return dp[i][j] = up + left;    
}

int countWays(int m, int n, vector<vector<int>> &mat){
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return mazeSolve(m-1, n-1, mat, dp);
}

int main(){
    vector<vector<int>> mat{{0, 0, 0},
                           {0, -1, 0},
                           {0, 0, 0}};
    int m = mat.size();
    int n = mat[0].size();

    cout << countWays(m, n, mat);
}