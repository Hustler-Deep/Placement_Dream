#include<bits/stdc++.h>
using namespace std;

//T.C.->O(2^(M * N))    S.C.->O((N-1)+(M-1)) + O(M * N)  --> TLE

int countHelper(int i, int j){
    if(i == 0 && j == 0) return 1;
    if(i<0 || j<0) return 0;

    int up = countHelper(i-1, j);
    int left = countHelper(i, j-1);

    return up + left;    
}

int countWays(int m, int n){
    return countHelper(m-1, n-1);
}

int main(){
    int m=3, n=2;
    cout << countWays(m,n);
}