class Solution {
public:
    int longestPalindrome(string s) {
        int freq[256] = {0};
        
        for(char ch : s)
        {
            freq[ch]++;
        }

        int maxlen = 0;
        bool hasodd = false;
        
        for(int i = 0; i < 256; i++)
        {
            if(freq[i] > 0)
            {
                if(freq[i] % 2 == 0)
                {
                    maxlen = maxlen+freq[i];
                }
                else
                {
                    maxlen += freq[i]-1;
                    hasodd = true;
                }

            }
        }

        if(hasodd)
        {
            maxlen+=1;
        }
        return maxlen;
        
        
    }
};