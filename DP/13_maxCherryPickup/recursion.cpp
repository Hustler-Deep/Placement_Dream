#include<bits/stdc++.h>
using namespace std;

//T.C. -> O(3^N * 3^N)    S.C.->O(N)

int maxUtil(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid){
    if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e9;

    if(i == n-1){
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }

    int maxi = -1e9;
    for(int di = -1; di <= 1; di++){
        for(int dj = -1; dj <= 1; dj++){
            int ans;
            if(j1 == j2)
                ans = grid[i][j1];
            else ans = grid[i][j1] + grid[i][j2];
            ans += maxUtil(i+1, j1+di, j2+dj, n, m, grid);
            maxi = max(maxi, ans);
        }
    }
    return maxi;
}

int maxPickup(int n, int m, vector<vector<int>> grid){
    return maxUtil(0, 0, m-1, n, m, grid);
}

int main(){
    vector<vector<int>> matrix{
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
    };
    int n = matrix.size();
    int m = matrix[0].size();

    cout << maxPickup(n, m, matrix);
}