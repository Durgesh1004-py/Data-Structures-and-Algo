class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i=0;
        int k1 = k;
        int ans = 0;
        while(i<nums.size())
        {
            if(nums[i]==k1)
            {
                i++;
                k1 = k1+k;

            }
            else if(nums[i]<k1)
            {
                i++;

            }
            else
            {
                return k1;

            }
        }
        return k1;
     
       
    }
};