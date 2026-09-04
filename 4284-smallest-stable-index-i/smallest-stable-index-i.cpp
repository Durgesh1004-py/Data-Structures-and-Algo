class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n= nums.size();

        vector<int> prefix(n);
        int maxi = nums[0];
        for(int i=0; i<n; i++)
        {
            maxi = max(nums[i],maxi);
            prefix[i] = maxi;
        }

        vector<int> sufix(n);
        int mini = nums[n-1];
        for(int i=n-1; i>=0; i--)
        {
            mini = min(mini, nums[i]);
            sufix[i] = mini;
        }
        int ans = -1;

        for(int i=0; i<n; i++)
        {
            if((prefix[i]-sufix[i])<=k)
            {
                ans = i;
                break;
            }
        }
        return ans;





        
    }
};