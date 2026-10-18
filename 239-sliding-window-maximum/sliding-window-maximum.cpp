class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> q; // stores indices, values are in decreasing order

        for (int i = 0; i < n; i++) {
            // 1. remove indices that are out of the window
            if (!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }

            // 2. remove smaller elements from the back
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }

            // 3. add current index
            q.push_back(i);

            // 4. record answer once the first window is formed
            if (i >= k - 1) {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};