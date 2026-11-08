class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int i=0;
        int n = s1.length();
        vector<vector<string>> ans;
        while(i<n)
        {
            string t1 = "";
            string t2 = "";
            while(i<n && s1[i]!=s2[i])
            {
                t1 +=s1[i];
                t2 +=s2[i];
                i++;
            }
            vector<string> store;
            if(t1!="")
            {
                store.push_back(t1);
                store.push_back(t2);
                ans.push_back(store);
            }
            i++;


        }
        return ans;
        
    }
};