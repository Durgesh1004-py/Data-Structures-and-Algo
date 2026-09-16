class Solution {
public:
    int houserob(int i,vector<int>& nums,vector<int> &dp)
    {
        if(i>=nums.size())
        {
            return 0;
        }

        if(dp[i]!=-1) return dp[i];

        int steal = nums[i] + houserob(i+2, nums,dp);
        int left = houserob(i+1, nums,dp);

        return dp[i] =  max(steal,left);


    }
    int rob(vector<int>& nums) {
        int sum = 0;
        int i=0;
        vector<int> dp(nums.size(), -1);
        return houserob(i,nums,dp);
        

    }
};