#include<bits/stdc++.h>
using namespace std;

//T.C.->O(N*M)   S.C.->O(N)

int minSum(int n, int m, vector<vector<int>> &mat){
    vector<int> prev(m, 0);
    for(int i=0; i<n; i++){
        vector<int> cur(m, 0);
        for(int j=0; j<m; j++){
            if(i==0 && j==0) cur[j] = mat[i][j];
            else {
                int up = mat[i][j];
                if(i>0) up += prev[j];
                else up += 1e9;

                int left = mat[i][j];
                if(j>0) left += cur[j-1];
                else left += 1e9;

                cur[j] = min(up, left);
            }
        }
        prev = cur;
    }
    return prev[m-1];
}

int main(){

    vector<vector<int>> mat{{5, 9, 6},
                            {11, 5, 2}};
    int n = mat.size();
    int m = mat[0].size();
    cout << minSum(n, m, mat);

    return 0;
}