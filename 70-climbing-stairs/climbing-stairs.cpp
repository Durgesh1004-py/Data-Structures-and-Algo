// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n<=3)
//         return n;

//         int prev1 = 2;
//         int prev2 = 3;
//         int curr = 0;

//         for(int i=3; i<n; i++)
//         {
//             curr = prev1+prev2;
//             prev1 = prev2;
//             prev2 = curr;

//         }
//         return curr;   
      
//     }
// };
class Solution {
public:
    int solve(int n, vector<int> &dp)
    {
        if(n<=3) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = solve(n-1,dp) + solve(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};