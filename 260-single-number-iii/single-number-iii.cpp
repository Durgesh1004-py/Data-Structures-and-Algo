class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long ximi = 0;
        for(int i=0; i<n; i++)
        {
            ximi = ximi^nums[i];
        }

        int rightnum = (ximi&(ximi-1))^ximi;
        int n1 = 0;
        int n2= 0;

        for(int i=0; i<n; i++)
        {
            if((nums[i] & rightnum)==0)
            {
                n1 = n1^nums[i];
            }
            else{
                n2 = n2^nums[i];
            }
        } 
        vector<int> ans;
        ans.push_back(n1);
        ans.push_back(n2);
        return ans;
    }
};