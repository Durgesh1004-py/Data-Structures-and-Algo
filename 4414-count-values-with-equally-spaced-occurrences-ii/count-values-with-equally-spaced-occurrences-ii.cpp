class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        unordered_map<int,vector<int>> mpp;
        for(int i=0; i<n; i++)
        {
            mpp[nums[i]].push_back(i);
        }
        for(auto it : mpp)
        {
            if(it.second.size()>=3)
            {
                int i=1;
                while(i<it.second.size()-1)
                {
                    if(it.second[i]-it.second[i-1]!=it.second[i+1]-it.second[i])
                    {
                        break;
                    }
                    if(i==it.second.size()-2)
                    {
                        count++;
                    }
                    i++;    
                }
            }
        }
        return count;
        
    }
};