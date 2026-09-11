class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minlen = INT_MAX;
        int i=0, j=0;
        int sum = 0;

        while(j<n)
        {
            sum = sum + nums[j];
            if(sum<target)
            {
                j++;
            }
            else
            {
                minlen = min(minlen, j-i+1);
                while(sum>=target)
                {
                    minlen = min(minlen, j-i+1);
                    sum -=nums[i];
                    i++;
                }
                j++;
            }
        }

        if(minlen == INT_MAX) return 0;
        return minlen;  
    }
};