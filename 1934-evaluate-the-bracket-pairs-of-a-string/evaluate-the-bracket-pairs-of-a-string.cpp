class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        string ans = "";

        unordered_map<string, string> mp;

        // Store knowledge in hashmap
        for(int i = 0; i < knowledge.size(); i++)
        {
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        int ns = s.length();

        for(int i = 0; i < ns; i++)
        {
            if(s[i] == '(')
            {
                string bdlna = "";

                i++;

                while(s[i] != ')')
                {
                    bdlna += s[i];
                    i++;
                }

                if(mp.find(bdlna) != mp.end())
                {
                    ans += mp[bdlna];
                }
                else
                {
                    ans += '?';
                }
            }
            else
            {
                ans += s[i];
            }
        }

        return ans;
    }
};