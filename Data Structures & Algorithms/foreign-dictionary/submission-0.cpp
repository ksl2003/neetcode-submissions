class Solution {
   private:
    vector<int> getTopoSort(vector<vector<int>>& adjList, vector<bool>& charPres) {
        // Get Indegrees
        int v = adjList.size();
        vector<int> inDeg(v, 0);
        for (int i = 0; i < v; i++) {
            for (auto a : adjList[i]) {
                inDeg[a]++;
            }
        }

        // Get all 0 indegree elements
        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (inDeg[i] == 0 && charPres[i]) {
                q.push(i);
            }
        }

        // Apply TopoSort
        vector<int> topoSort;
        while (!q.empty()) {
            auto ele = q.front();
            q.pop();
            topoSort.push_back(ele);

            for (auto a : adjList[ele]) {
                inDeg[a]--;

                if (inDeg[a] == 0) {
                    q.push(a);
                }
            }
        }

        return topoSort;
    }

   public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adjList(26);
        vector<bool> charPres(26, false);
        for (auto a : words) {
            for (auto b : a) {
                charPres[b - 'a'] = true;
            }
        }
        // sort(words.begin(), words.end(), comp);
        int n = words.size();
        for (int i = 0; i < n - 1; i++) {
            string presWord = words[i];
            string presWord2 = words[i + 1];
            int lenWord = min(presWord.size(), presWord2.size());
            bool found = false;

            for (int k = 0; k < lenWord; k++) {
                if (presWord[k] != presWord2[k]) {
                    adjList[presWord[k] - 'a'].push_back(presWord2[k] - 'a');
                    found = true;
                    break;
                }
            }
            if (!found && presWord.size() > presWord2.size()) {
                return "";
            }
        }

        vector<int> topoSort = getTopoSort(adjList, charPres);

        int charCount = 0;

        for (auto a : charPres) {
            if (a) charCount++;
        }

        if (topoSort.size() != charCount) {
            return "";
        }

        string ans = "";

        for (auto a : topoSort) {
            ans.push_back((char)a + 'a');
        }
        return ans;
    }
};
