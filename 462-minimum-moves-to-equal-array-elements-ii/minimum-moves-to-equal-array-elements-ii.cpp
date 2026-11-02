class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int change = nums[nums.size()/2], ans = 0;
        for (int num : nums) ans += abs(change-num);
        return ans;
    }
};