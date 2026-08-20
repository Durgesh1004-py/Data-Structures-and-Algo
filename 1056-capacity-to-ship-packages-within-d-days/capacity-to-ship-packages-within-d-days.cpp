class Solution {
public:
    int capacity(vector<int>& weights, int days, int mid)
    {
        
        int n = weights.size();
        int desired_day = 1;
        int sumi = 0;

        for(int i=0; i<n; i++)
        {
            if(sumi+weights[i]>mid)
            {
                desired_day++;
                sumi = 0;
            }
            sumi += weights[i];
        }

        return desired_day;
        
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int i = 0;
        int n = weights.size();
        int max_ele = *max_element(weights.begin(), weights.end());
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum = sum + weights[i];
        } 

        
       
        int mid =(max_ele + sum)/2;
        int desired_day = 0;

        while(max_ele<=sum)
        {
            int mid =(max_ele + sum)/2;
            int desired_day = capacity(weights, days, mid);

            if(desired_day<=days)
            {
                sum = mid-1;
            }
            else
            {
                max_ele = mid+1;
            }
            
        }
        return max_ele;


    }
};