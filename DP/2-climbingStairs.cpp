#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n; cin >> n;

    /*
    // Tabulation -> T.C.->O(N)     S.C.->O(N)
    vector<int> dp(n+1, -1);
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }    
    cout << dp[n];
    */

    //Space optimization -> T.C.->O(N)     S.C.->O(1)
    int prev2 = 1;
    int prev = 1;

    for(int i=2; i<=n; i++){
        int curi = prev2 + prev;
        prev2 =prev;
        prev = curi;
    }
    cout << prev;

    return 0;
}
