class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>presum(n);
        vector<int>sufsum(n);

        //prefix sum
        presum[0] = nums[0];
        for(int i=1; i<n; i++){
            presum[i] = max(nums[i], presum[i-1]);
                
        }

        //sufix sum
        sufsum[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            sufsum[i] = min(sufsum[i+1], nums[i]); 
        }

        for(int i=0; i<n; i++){
            if(presum[i]-sufsum[i]<=k)
                return i;
        }
        return -1;
        
    }
};