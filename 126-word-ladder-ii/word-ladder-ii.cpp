class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> result;

        if (dict.find(endWord) == dict.end()) return result;

        unordered_map<string, vector<string>> adj;
        unordered_set<string> current_level{beginWord};
        bool found = false;

        while (!current_level.empty() && !found) {
            for (const auto& word : current_level) dict.erase(word);

            unordered_set<string> next_level;

            for (const auto& word : current_level) {
                string temp = word;

                for (int i = 0; i < temp.size(); i++) {
                    char original = temp[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;

                        if (dict.find(temp) != dict.end()) {
                            next_level.insert(temp);
                            adj[temp].push_back(word);
                            if (temp == endWord) found = true;
                        }
                    }

                    temp[i] = original;
                }
            }

            current_level = move(next_level);
        }

        if (!found) return result;

        vector<string> path = {endWord};
        dfs(endWord, beginWord, adj, path, result);
        return result;
    }

    void dfs(string word, string& beginWord, unordered_map<string, vector<string>>& adj,
             vector<string>& path, vector<vector<string>>& result) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            result.push_back(temp);
            return;
        }

        for (auto& prev : adj[word]) {
            path.push_back(prev);
            dfs(prev, beginWord, adj, path, result);
            path.pop_back();
        }
    }
};