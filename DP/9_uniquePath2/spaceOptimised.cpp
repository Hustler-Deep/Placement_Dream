#include<bits/stdc++.h>
using namespace std;

//T.C.->O((M * N))    S.C.->O(N)

int mazeSolve(int m, int n, vector<vector<int>> &mat){
    vector<int> prev(n, 0);
    for(int i=0; i<m; i++){
        vector<int> cur(n, 0);
        for(int j=0; j<n; j++){
            if(i>0 && j>0 && mat[i][j] == -1) {
                cur[j] = 0;
                continue;
            }
            if(i == 0 && j == 0){
                cur[j] = 1;
                continue;
            }
            int up = 0, left = 0;
            if(i>0) up = prev[j];
            if(j>0) left = cur[j-1];

            cur[j] = up + left;
        }
        prev = cur;
    }   
    return prev[n-1];
}

int countWays(int m, int n, vector<vector<int>> &mat){
    
    return mazeSolve(m, n, mat);
}

int main(){
    vector<vector<int>> mat{{0, 0, 0},
                           {0, -1, 0},
                           {0, 0, 0}};
    int m = mat.size();
    int n = mat[0].size();

    cout << countWays(m, n, mat);
}