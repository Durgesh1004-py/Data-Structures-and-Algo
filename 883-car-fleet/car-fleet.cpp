class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,int>> car;
        car.reserve(n);
        for(int i=0; i<n; i++)
        {
            car.push_back({position[i],speed[i]});
        }

        sort(car.begin(), car.end());
        stack<double> st;
        for(int i=0; i<n; i++)
        {   double time = (target - car[i].first) / (double)car[i].second;
            while(!st.empty() && st.top()<=time)
            {
                st.pop();
            }
            st.push(time);
        }
        return st.size();    
    }
};