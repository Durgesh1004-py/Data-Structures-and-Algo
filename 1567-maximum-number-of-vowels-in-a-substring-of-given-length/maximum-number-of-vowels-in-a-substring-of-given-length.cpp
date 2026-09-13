class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        queue<int>q;
        int count=0;
        for(int i=0; i<k; i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            {
                q.push(i);
                count++;
            }
        }
        int j = 0;
        int maxi = count;

        for(int i=k; i<n; i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            {
                q.push(i);
                count++;
            }
            if(q.front()==j)
            {
                count--;
                q.pop();
            }
            j++;
            maxi = max(count, maxi);
        }
        return maxi;

        
    }
};