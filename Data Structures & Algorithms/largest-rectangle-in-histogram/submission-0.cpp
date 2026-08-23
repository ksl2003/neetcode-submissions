class Solution {
   private:
    void findNse(vector<int>& nse, vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            int presEle = arr[i];

            while (!s.empty() && presEle <= arr[s.top()]) {
                s.pop();
            }

            if (!s.empty()) {
                nse[i] = s.top();
            }
            s.push(i);
        }
    }

    void findPse(vector<int>& pse, vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        for (int i = 0; i < n; i++) {
            int presEle = arr[i];

            while (!s.empty() && presEle <= arr[s.top()]) {
                s.pop();
            }

            if (!s.empty()) {
                pse[i] = s.top();
            }
            s.push(i);
        }
    }

   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n, -1);
        vector<int> pse(n, -1);

        findNse(nse, heights);
        findPse(pse, heights);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int first = pse[i];
            int last = nse[i] == -1 ? n : nse[i];

            int width = (last - first) - 1;
            int len = heights[i];

            int result = len * width;
            ans = max(ans, result);
        }
        return ans;
    }
};
