class Solution {
public:
    int hammingDistance(int x, int y) {
        int val = x^y;
        int cnt = 0;

        while(val!=0)
        {
            if(val%2==1)
            {
                cnt++;
            }
            val = val>>1;
        }
        return cnt;
        
    }
};