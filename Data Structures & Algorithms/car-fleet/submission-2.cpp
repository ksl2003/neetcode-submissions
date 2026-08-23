class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> v;
        int n = position.size();

        for(int i = 0; i < n; i++){
            v.push_back({position[i], speed[i]});
        }
        sort(v.begin(), v.end());
        vector<double> times(n);

        for(int i = 0; i < n; i++){
            times[i] = (double)(target - v[i].first) / v[i].second;
        }

        stack<double> s;
        int presFleet = 0;
        for(int i = n - 1; i >= 0; i--){
            double presEle = times[i];
            while(!s.empty() && s.top() < presEle){
                s.pop();
            }
            if(s.empty()){
                presFleet++;
            }
            s.push(presEle);
        }

        return presFleet;
    }
};