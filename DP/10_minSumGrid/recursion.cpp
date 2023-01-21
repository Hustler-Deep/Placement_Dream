#include<bits/stdc++.h>
using namespace std;

//T.C.->O(2^(N*M))   S.C.->O((M-1)+(N-1) + N*M)

int gridSolver(int i, int j, vector<vector<int>> &mat){
    if(i == 0 && j == 0) return mat[i][j];
    if(i<0 || j<0) return 1e9;

    int up = mat[i][j] + gridSolver(i-1, j, mat);
    int left = mat[i][j] + gridSolver(i, j-1, mat);

    return min(up, left);
}

int minSum(int n, int m, vector<vector<int>> &mat){
    return gridSolver(n-1, m-1, mat);
}

int main(){

    vector<vector<int>> mat{{5, 9, 6},
                            {11, 5, 2}};
    int n = mat.size();
    int m = mat[0].size();
    cout << minSum(n, m, mat);

    return 0;
}