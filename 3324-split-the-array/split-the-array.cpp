class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int cnt = 0;
        int prev = nums[0];

        for(int i = 0; i < n; i++)
        {
            if(nums[i] != prev)
            {
                cnt = 1;
                prev = nums[i];
            }
            else
            {
                cnt++;
            }

            if(cnt > 2)
                return false;
        }

        return true;
    }
};