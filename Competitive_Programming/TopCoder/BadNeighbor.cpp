#include <bits/stdc++.h>
using namespace std;


class BadNeighbors
{
	public:
    int maxDonations(vector<int> a){
        int n = a.size();
        vector<int> dp(1005,0);
    vector<int> dp1(1005,0);

    //if 0 index is taken
    dp[0] = a[0];
    for(int i = 1; i <= n-2; i++){
        if(i == 1){
            dp[1] = max(dp[0],dp[1]);
            }
        else
        dp[i]=max(dp[i-1],dp[i-2]+a[i]);
    }
    dp[n-1]=dp[n-2];
    // if 0 not taken
        dp[0] = 0;
        dp1[1]=a[1]; 
    for(int i = 2; i <= n-1; i++){
        dp1[i]=max(dp1[i-1],dp1[i-2]+a[i]);
    }
    return max(dp[n-1],dp1[n-1]);

        }
};