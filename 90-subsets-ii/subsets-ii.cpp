class Solution {
public:
    void dupliset(int i, vector<int>& nums, vector<int> &ds, set<vector<int>> &ans)
    {
        if(i>=nums.size())
        {
            ans.insert(ds);
            return;
        }
        ds.push_back(nums[i]);
        dupliset(i+1, nums, ds, ans);
        ds.pop_back();
        dupliset(i+1, nums ,ds, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        set<vector<int>> ans;
        vector<int> ds;
        int i=0;
        
        dupliset(i, nums, ds, ans);
       

        vector<vector<int>> realans(ans.begin(), ans.end());
        return realans;
        
    }
};