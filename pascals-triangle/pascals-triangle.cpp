class Solution {
    const int mod = 1e9 + 7;
public:
    vector<int> nthRowOfPascalTriangle(int n) {
        vector<int> ansRow;
        for(int i = 0; i < n; i++){
            ansRow.push_back(1);
            for(int j = i-1; j>=1; j--){
                ansRow[j] = (ansRow[j] + ansRow[j-1]) % mod;
            }
        }    
        return ansRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int row=1; row<=numRows; row++){
            ans.push_back(nthRowOfPascalTriangle(row));
        }
        return ans;
    }
};