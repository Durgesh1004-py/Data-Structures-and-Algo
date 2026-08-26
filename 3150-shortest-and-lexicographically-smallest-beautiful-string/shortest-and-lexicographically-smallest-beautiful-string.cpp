class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i = 0;
        int j = 0;

        string ans = "";
        int ones = 0;
        int minlen = INT_MAX;

        int n = s.size();

        while(j < n)
        {
            if(s[j] == '1')
                ones++;

            while(ones >= k)
            {
                string curr = s.substr(i, j-i+1);

                if(j-i+1 < minlen)
                {
                    minlen = j-i+1;
                    ans = curr;
                }
                else if(j-i+1 == minlen && curr < ans)
                {
                    ans = curr;
                }

                if(s[i] == '1')
                    ones--;

                i++;
            }

            j++;
        }

        return ans;
    }
};