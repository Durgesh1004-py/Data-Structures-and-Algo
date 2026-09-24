class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int ans =-1;
        for(int i=0; i<n; i++)
        {
            if(nums[i]<=9)
            {
                if(nums[i]==i)
                {
                    ans = i;
                    break;
                }
            }    
            else
            {
                int n1 = nums[i];
                int sum = 0;
                while(n1!=0)
                {
                    sum = sum+n1%10;
                    n1 = n1/10;
                }
                if(sum==i)
                {
                    ans = i;
                    break;
                }
            }
            
        }
        return ans;
        
    }
};