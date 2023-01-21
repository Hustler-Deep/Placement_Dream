#include<bits/stdc++.h>
using namespace std;

//T.C. -> O(3^N)   S.C.->O(N)

int maxSumUtil(int i, int j, int m, vector<vector<int>> &matrix){
    if(j<0 || j>=m) return -1e9;
    if(i==0) return matrix[0][j];

    int up = matrix[i][j] + maxSumUtil(i-1, j, m, matrix);
    int leftDiagonal = matrix[i][j] + maxSumUtil(i-1, j-1, m, matrix);
    int rightDiagonal = matrix[i][j] + maxSumUtil(i-1, j+1, m, matrix);

    return max(up, max(leftDiagonal, rightDiagonal));
}

int getMaxPathSum(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    int maxi = INT_MIN;
    for(int j=0; j<m; j++){
        int ans = maxSumUtil(n-1, j, m, matrix);
        maxi = max(maxi, ans);
    }
    return maxi;
}

int main(){
    vector<vector<int>> matrix{{1,2,10,4},
                              {100,3,2,1},
                              {1,1,20,2},
                              {1,2,2,1}};
    cout << getMaxPathSum(matrix);
}