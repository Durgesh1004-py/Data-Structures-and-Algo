class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left;
        vector<int> right;
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==pivot) cnt++;
        }

        for(int i=0; i<n; i++)
        {
            if(nums[i]<pivot)
            {
                left.push_back(nums[i]);
            }
            else if(nums[i]>pivot)
            {
                right.push_back(nums[i]);
            }
        }

        while(cnt)
        {
            left.push_back(pivot);
            cnt--;
        }
        left.insert(left.end(), right.begin(), right.end());

        return left;
        
    }
};