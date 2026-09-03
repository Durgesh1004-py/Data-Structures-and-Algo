class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        vector<int> nums2;

        for(int i=0; i<n; i++)
        {
            if(nums1[i]%2==0)
            {
                nums2.push_back(nums1[i]);
            }
        }

        if(nums1==nums2) return true;

        int mn = *min_element(nums1.begin(), nums1.end());
        return (mn%2==1);

        
    }
};