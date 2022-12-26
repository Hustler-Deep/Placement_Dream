#include<bits/stdc++.h>
using namespace std;

//T.C.->O((M * N))    S.C.->O((M * N))

int mazeSolve(int m, int n, vector<vector<int>> &mat, vector<vector<int>> &dp){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i>0 && j>0 && mat[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            if(i == 0 && j == 0){
                dp[i][j] = 1;
                continue;
            }
            int up = 0, left = 0;
            if(i>0) up = dp[i-1][j];
            if(j>0) left = dp[i][j-1];

            dp[i][j] = up + left;
        }
    }   
    return dp[m-1][n-1];
}

int countWays(int m, int n, vector<vector<int>> &mat){
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return mazeSolve(m, n, mat, dp);
}

int main(){
    vector<vector<int>> mat{{0, 0, 0},
                           {0, -1, 0},
                           {0, 0, 0}};
    int m = mat.size();
    int n = mat[0].size();

    cout << countWays(m, n, mat);
}