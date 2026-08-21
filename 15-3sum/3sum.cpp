class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i=0;
        int n = nums.size();
        set<vector<int>> st;
      
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
                
            int k = i+1;
            int j = n-1;
            

            while(k<j)
            {
                if((nums[i]+nums[j]+nums[k])==0)
                {
                   
                    vector<int> ans1;
                    ans1.push_back(nums[i]);
                    ans1.push_back(nums[k]);
                    ans1.push_back(nums[j]);
                 
                  
                    st.insert(ans1);
                    k++;
                    j--;
                   
                   
                }
                else if((nums[i]+nums[j]+nums[k])<0)
                {
                    k++;
                }
                else
                {
                    j--;
                }

            }

        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;

    }
};