class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

         int n = nums.size();

        if (k == 1) {
            unordered_map<int, int> freq;

            for (int y : nums)
                freq[y]++;

            int ans = -1;

            for (auto &t : freq) {
                if (t.second == 1)
                    ans = max(ans, t.first);
            }

            return ans;
        }

          if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        unordered_map<int, int> freq;
        for (int x : nums)
            freq[x]++;

        int ans = -1;

        if (freq[nums[0]] == 1)
            ans = max(ans, nums[0]);
            
        if (freq[nums[n - 1]] == 1)
            ans = max(ans, nums[n - 1]);

        return ans;
    }
};