// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
//     }
// };

class Solution {
  public:
    int ladderLength(string startWord, string targetWord,
                         vector<string>& wordList) {
        
        // queue of {currentWord, stepsTaken}
        queue<pair<string, int>> q;
        q.push({startWord, 1});

        // insert all dictionary words into set for O(1) lookup
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);  // remove if startWord exists

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == targetWord)
                return steps;

            // try all possible single character transformations
            for (int i = 0; i < word.size(); ++i) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    word[i] = ch;
                    if (st.find(word) != st.end()) {
                        st.erase(word);  // mark as visited
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original; // revert for next character
            }
        }

        return 0;  // no path found
    }
};
