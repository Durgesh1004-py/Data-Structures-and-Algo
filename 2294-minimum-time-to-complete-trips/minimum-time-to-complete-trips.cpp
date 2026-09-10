class Solution {
public:
    bool cancomplete(vector<int>& time, int totalTrips, long long mid)
    {
        long long count = 0;
        int n = time.size();
        for(int i=0; i<n; i++)
        {
            count += mid/time[i];
            if(count >= totalTrips) return true;
                
        }
        
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long maxele = *max_element(time.begin(), time.end());
        long long low = 1;
        long long high = maxele*totalTrips;
        long long ans;

        while(low<=high)
        {
            long long mid = low+(high-low)/2;
            if(cancomplete(time, totalTrips, mid))
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
        
    }
};