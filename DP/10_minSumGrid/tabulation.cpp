#include<bits/stdc++.h>
using namespace std;

//T.C.->O(N*M)   S.C.->O(N*M)

int minSum(int n, int m, vector<vector<int>> &mat){
    vector<vector<int>> dp(n, vector<int> (m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) dp[i][j] = mat[i][j];
            else {
                int up = mat[i][j];
                if(i>0) up += dp[i-1][j];
                else up += 1e9;

                int left = mat[i][j];
                if(j>0) left += dp[i][j-1];
                else left += 1e9;

                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n-1][m-1];
}

int main(){

    vector<vector<int>> mat{{5, 9, 6},
                            {11, 5, 2}};
    int n = mat.size();
    int m = mat[0].size();
    cout << minSum(n, m, mat);

    return 0;
}