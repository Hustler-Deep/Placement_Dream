#include<bits/stdc++.h>
using namespace std;

//T.C.->O(2^(N*N))  S.C.->O(N)

int solveUtil(int i, int j, vector<vector<int>> &triangle, int n){
    if(i == n-1) return triangle[i][j];

    int down = triangle[i][j] + solveUtil(i+1, j, triangle, n);
    int diagonal = triangle[i][j] + solveUtil(i+1, j+1, triangle, n);

    return min(down, diagonal);
}

int minimumPathSum(vector<vector<int>> &triangle, int n){
    return solveUtil(0, 0, triangle, n);
}

int main(){

    vector<vector<int>> triangle{{1},
                                 {2,3},
                                 {3,6,7},
                                 {8,9,6,10}};
    int n = triangle.size();
    cout << minimumPathSum(triangle, n);

}