class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0;
        int j = nums.size()-2;
        long long sum = 0;

        while(i<j)
        {
            sum = sum + nums[j];
            j = j-2;
            i++;

        }
        return sum;
    }
};