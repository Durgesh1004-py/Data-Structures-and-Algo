class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int i=0;
        int n = nums.size();
        int j = n-1;

        int maxele = INT_MIN;
        int minele = INT_MAX;

        int maxi = 0;
        int maxj = 0;
        while(i<n)
        {
            if(nums[i]>maxele)
            {
                maxele = max(maxele, nums[i]);
                maxi = i;
            }
            if(nums[i]<minele)
            {
                minele = min(minele, nums[i]);
                maxj = i;
            }
            i++;
        }
        int ans = 0;
        maxi +=1;
        maxj +=1;
        int backmaxi = n-maxi+1;
        int backmaxj = n-maxj+1;

        int front_val = max(maxi,maxj);
        int back_val = max(backmaxi, backmaxj);
        int forntibackj = maxi + backmaxj;
        int backifrontj = backmaxi + maxj;

        return min(min(backifrontj,forntibackj), min(back_val,front_val));
        
    }
};