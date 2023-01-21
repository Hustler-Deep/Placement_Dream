#include<bits/stdc++.h>
using namespace std;

//T.C.->O((N*M))   S.C.->O((M-1)+(N-1) + N*M)

int gridSolver(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp){
    if(i == 0 && j == 0) return mat[i][j];
    if(i<0 || j<0) return 1e9;
    if(dp[i][j] != -1) return dp[i][j];

    int up = mat[i][j] + gridSolver(i-1, j, mat, dp);
    int left = mat[i][j] + gridSolver(i, j-1, mat, dp);

    return dp[i][j] = min(up, left);
}

int minSum(int n, int m, vector<vector<int>> &mat){
    vector<vector<int>> dp(n, vector<int> (m, -1));
    return gridSolver(n-1, m-1, mat, dp);
}

int main(){

    vector<vector<int>> mat{{5, 9, 6},
                            {11, 5, 2}};
    int n = mat.size();
    int m = mat[0].size();
    cout << minSum(n, m, mat);

    return 0;
}