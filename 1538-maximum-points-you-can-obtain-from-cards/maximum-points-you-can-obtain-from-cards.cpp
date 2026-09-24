class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = accumulate(cardPoints.begin(), cardPoints.end(),0);
        if(n==k || n==1) return sum;
        int ans = 0;

        int lsum = accumulate(cardPoints.begin(),cardPoints.begin()+k,0);
        int maxsum = lsum;
        int r = n-1;

        for(int i=0; i<k; i++)
        {
            lsum = lsum-cardPoints[k-i-1]+cardPoints[n-1-i];
            maxsum = max(maxsum, lsum);
        }
        return maxsum;

        


        
    }
};