class Solution {
public:
    int cntret(vector<int>& nums, int goal)
    {
        if(goal<0) return 0;
        int l=0,r=0;
        int sum=0,cnt=0;
        while(r<nums.size())
        {
            sum = sum+nums[r];

            while(sum>goal)
            {
                sum = sum-nums[l];
                l++;
            }
            cnt = cnt + (r-l+1);
            r+=1;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return cntret(nums,goal)-cntret(nums,goal-1);

    }
};