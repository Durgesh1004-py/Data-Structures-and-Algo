class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int cnt = 0;
        sort(people.begin(), people.end());
        int j = people.size()-1;
        int i=0;
        
        while(i<=j)
        {
            if((people[i]+people[j])<=limit)
            {
                i++;
            }
            j--;
            cnt++;
        }
        return cnt;

              
    }
};