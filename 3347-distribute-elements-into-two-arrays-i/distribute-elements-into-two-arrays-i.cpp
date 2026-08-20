class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
       
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int i = 2;
        int n = nums.size();


        while(i<n)
        {
            int n1 = arr1.size();
            int n2 = arr2.size();

            if(arr1[n1-1]>arr2[n2-1])
            {
                arr1.push_back(nums[i]);
                i++;

            }
            else
            {
                arr2.push_back(nums[i]);
                i++;
            }

        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());

        return arr1;
         
    }
};