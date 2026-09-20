class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0;
        int zerocnt = 0;
        int i=0, j=0;
        while(j<nums.size())
        {
            if(nums[j]==0)
            {
                zerocnt++;
            }
            if(zerocnt>k)
            {
                if(nums[i]==0) zerocnt--;
                i++;
            }
            if(zerocnt<=k)
            {
                int len = j-i+1;
                maxlen = max(len,maxlen);
            }
            j++;
           
        }
        return maxlen;
        
    }
};